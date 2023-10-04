import cv2
import math
import numpy as np

file_src = 'src_depth_hand.png'
file_dst = 'dst.png'

img_src = cv2.imread(file_src, cv2.IMREAD_GRAYSCALE)

cv2.namedWindow('src')
cv2.namedWindow('dst')

depth_min = 173
depth_max = 254
img_dst = cv2.inRange(img_src, depth_min, depth_max)

cv2.imshow('src', img_src)
cv2.imshow('dst', img_dst)
cv2.imwrite(file_dst, img_dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
