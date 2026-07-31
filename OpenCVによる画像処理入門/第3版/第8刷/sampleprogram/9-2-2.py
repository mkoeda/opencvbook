import cv2
import math
import numpy as np

file_src1 = 'src1.png'
file_src2 = 'src2.png'
file_dst = 'dst.png'

img_src1 = cv2.imread(file_src1, cv2.IMREAD_COLOR)
img_src2 = cv2.imread(file_src2, cv2.IMREAD_COLOR)

cv2.namedWindow('src1')
cv2.namedWindow('src2')
cv2.namedWindow('dst')

# 入力画像 1 を濃淡画像に変換
img_g1 = cv2.cvtColor(img_src1, cv2.COLOR_BGR2GRAY)
# マスク画像生成のための2値化
img_mskg = cv2.threshold(img_g1, 200, 255, cv2.THRESH_BINARY_INV)[1]
# マスク画像 ( カラー ) 生成
img_msk = cv2.merge((img_mskg, img_mskg, img_mskg))
# 入力画像 1 からマスク画像の部分だけを切り出す ( 切り出し画像 1)
img_s1m = cv2.bitwise_and(img_src1, img_msk)
# マスク画像の反転
img_mskn = cv2.bitwise_not(img_msk)
# 入力画像 2 からマスク画像の反転部分だけを切り出す ( 切り出し画像 2)
img_s2m = cv2.bitwise_and(img_src2, img_mskn)
# 切り出し画像 1 と切り出し画像 2 を合成
img_dst = cv2.bitwise_or(img_s1m, img_s2m)

cv2.imshow('src1', img_src1)  # 入力画像1を表示
cv2.imshow('src2', img_src2)  # 入力画像2を表示
cv2.imshow('dst', img_dst)  # 出力画像を表示
cv2.imwrite(file_dst, img_dst)  # 処理結果の保存

cv2.waitKey(0)  # キー入力待ち
cv2.destroyAllWindows()
