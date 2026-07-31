import cv2
import math
import numpy as np

file_src = 'src_depth_wall.png'
file_dst = 'dst.png'

img_src = cv2.imread(file_src, cv2.IMREAD_GRAYSCALE)

cv2.namedWindow('src')
cv2.namedWindow('dst')

rows, cols = img_src.shape
img_dst = np.zeros([rows, cols]).astype(np.uint8)

for i in range(1, 256, 5):
  print(i)
  img_tmp = cv2.compare(img_src, i, cv2.CMP_EQ)
  img_dst = cv2.bitwise_or(img_tmp, img_dst)

cv2.imshow('src', img_src)
cv2.imshow('dst', img_dst)

cv2.imwrite(file_dst, img_dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
