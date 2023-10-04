import cv2
import math
import numpy as np

file_src = 'src.png'
file_dst = 'dst.png'

img_src = cv2.imread(file_src, cv2.IMREAD_COLOR)

cv2.namedWindow('src')
cv2.namedWindow('dst')

center = tuple(np.array([img_src.shape[1] * 0.5, img_src.shape[0] * 0.5]))
angle = 45.0
scale = 1.0
size = tuple(np.array([img_src.shape[1], img_src.shape[0]]))
rot_mat = cv2.getRotationMatrix2D(center, angle, scale)
img_dst = cv2.warpAffine(img_src, rot_mat, size, flags = cv2.INTER_CUBIC)

cv2.imshow('src', img_src)  # 入力画像を表示
cv2.imshow('dst', img_dst)  # 出力画像を表示
cv2.imwrite(file_dst, img_dst)  # 処理結果の保存

cv2.waitKey(0)  # キー入力待ち
cv2.destroyAllWindows()
