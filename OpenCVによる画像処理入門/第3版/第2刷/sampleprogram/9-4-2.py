import cv2
import math
import numpy as np

file_src1 = 'src1.png'
file_src2 = 'src2.png'
file_src3 = 'src3.png'
file_dst = 'dst.png'

img_src1 = cv2.imread(file_src1, cv2.IMREAD_GRAYSCALE)
img_src2 = cv2.imread(file_src2, cv2.IMREAD_GRAYSCALE)
img_src3 = cv2.imread(file_src3, cv2.IMREAD_GRAYSCALE)

cv2.namedWindow('src1')
cv2.namedWindow('src2')
cv2.namedWindow('src3')
cv2.namedWindow('dst')

# img_src1  画像 A( 時刻 t に取得 )
# img_src2  画像 B( 時刻 t+1 に取得 )
# img_src3  画像 C( 時刻 t+2 に取得 )
# 画像 A と B の差分画像を計算
img_df1 = cv2.absdiff(img_src1, img_src2)
# 画像 B と C の差分画像を計算
img_df2 = cv2.absdiff(img_src2, img_src3)
# それぞれの差分画像を二値化
img_df1b = cv2.threshold(img_df1, 20, 255, cv2.THRESH_BINARY)[1]
img_df2b = cv2.threshold(img_df2, 20, 255, cv2.THRESH_BINARY)[1]
# 二値化された差分画像の共通部分を取得
img_m = cv2.bitwise_and(img_df1b, img_df2b)
# 膨張・収縮してマスク画像を生成
op = np.ones((3, 3), np.uint8)
img_md = cv2.dilate(img_m, op, iterations=3)
img_msk = cv2.erode(img_md, op, iterations=3)
# マスクをかける
img_dst = cv2.bitwise_and(img_src2, img_msk)

cv2.imshow('src1', img_src1)  # 入力画像1を表示
cv2.imshow('src2', img_src2)  # 入力画像2を表示
cv2.imshow('src3', img_src3)  # 入力画像3を表示
cv2.imshow('dst', img_dst)  # 出力画像を表示
cv2.imwrite(file_dst, img_dst)  # 処理結果の保存

cv2.waitKey(0)  # キー入力待ち
cv2.destroyAllWindows()
