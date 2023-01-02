import cv2
import math
import numpy as np

file_src1 = 'src1.png'
file_src2 = 'src2.png'
file_dst = 'dst.png'

img_src1 = cv2.imread(file_src1, 1)
img_src2 = cv2.imread(file_src2, 1)

cv2.namedWindow('src1')
cv2.namedWindow('src2')
cv2.namedWindow('dst')

img_dst = cv2.addWeighted(img_src1, 0.5, img_src2, 0.5, 0.0)

cv2.imshow('src1', img_src1)  # 入力画像1を表示
cv2.imshow('src2', img_src2)  # 入力画像2を表示
cv2.imshow('dst', img_dst)  # 出力画像を表示
cv2.imwrite(file_dst, img_dst)  # 処理結果の保存

cv2.waitKey(0)  # キー入力待ち
cv2.destroyAllWindows()
