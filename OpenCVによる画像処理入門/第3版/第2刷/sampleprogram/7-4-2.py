import cv2
import math
import numpy as np

file_src = 'src.png'
file_dst = 'dst.png'

img_src = cv2.imread(file_src, cv2.IMREAD_GRAYSCALE)

cv2.namedWindow('src')
cv2.namedWindow('dst')

k = 1.0
op = np.array([[-k, -k,        -k],
               [-k, 1 + 8 * k, -k],
               [-k, -k,        -k]])
img_tmp = cv2.filter2D(img_src, -1, op)
img_dst = cv2.convertScaleAbs(img_tmp, alpha = 1, beta = 0)

cv2.imshow('src', img_src)  # 入力画像を表示
cv2.imshow('dst', img_dst)  # 出力画像を表示
cv2.imwrite(file_dst, img_dst)  # 処理結果の保存

cv2.waitKey(0)  # キー入力待ち
cv2.destroyAllWindows()
