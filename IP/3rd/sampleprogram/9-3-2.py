import cv2
import math
import numpy as np

file_src = 'src.jpg'
file_bkg = 'bkg.jpg'
file_dst = 'dst.jpg'

img_src = cv2.imread(file_src, 0)
img_bkg = cv2.imread(file_bkg, 0)

cv2.namedWindow('src')
cv2.namedWindow('bkg')
cv2.namedWindow('dst')

# 背景画像との差分画像を計算
img_df = cv2.absdiff(img_src, img_bkg)
# 差分画像の二値化
img_m = cv2.threshold(img_df, 120, 255, cv2.THRESH_BINARY)[1]
# 膨張・収縮してマスク画像を生成
op = np.ones((3, 3), np.uint8)
img_md = cv2.dilate(img_m, op, iterations=4)
img_msk = cv2.erode(img_md, op, iterations=4)
# マスク画像を使って対象を切り出す
img_dst = cv2.bitwise_and(img_src, img_msk)

cv2.imshow('src', img_src)  # 入力画像を表示
cv2.imshow('bkg', img_bkg)  # 背景画像を表示
cv2.imshow('dst', img_dst)  # 出力画像を表示
cv2.imwrite(file_dst, img_dst)  # 処理結果の保存

cv2.waitKey(0)  # キー入力待ち
cv2.destroyAllWindows()
