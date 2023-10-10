import cv2
import math
import numpy as np

file_src = 'src_bin_circle.png'
file_dst = 'dst.png'

img_src = cv2.imread(file_src, cv2.IMREAD_GRAYSCALE)

cv2.namedWindow('src')
# cv2.namedWindow('dst')

contours = cv2.findContours(img_src, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[0]
area = cv2.contourArea(contours[0])  # 面積
perimeter = cv2.arcLength(np.array(contours[0]), True)  # 周囲長
roundness = 4 * np.pi * area / perimeter / perimeter  # 円形度
print(area, perimeter, roundness)

cv2.imshow('src', img_src)  # 入力画像を表示
# cv2.imshow('dst', img_dst) # 出力画像を表示
# cv2.imwrite(file_dst, img_dst) # 処理結果の保存

cv2.waitKey(0)  # キー入力待ち
cv2.destroyAllWindows()
