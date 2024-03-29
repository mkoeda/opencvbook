import cv2
import math
import numpy as np

file_src = 'src_bin_labeling.png'
file_dst = 'dst.png'

img_src = cv2.imread(file_src, cv2.IMREAD_GRAYSCALE)

cv2.namedWindow('src')
cv2.namedWindow('dst')

num_lab, img_lab = cv2.connectedComponents(img_src)  # ラベリング
img_dst = cv2.compare(img_lab, 1, cv2.CMP_EQ)  # ラベル1を抜き出し

cv2.imshow('src', img_src)
cv2.imshow('dst', img_dst)

cv2.imwrite('img_label.png', img_dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
