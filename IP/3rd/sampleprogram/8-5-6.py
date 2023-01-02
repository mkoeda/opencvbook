import cv2
import math
import numpy as np

file_src = 'src_bin_ellipse.png'
file_dst = 'dst.png'

img_src = cv2.imread(file_src, 0)

cv2.namedWindow('src')
# cv2.namedWindow('dst')

m = cv2.moments(img_src)
area = m['m00']
x_g = m['m10'] / m['m00']
y_g = m['m01'] / m['m00']
ang = 0.5 * math.atan2(2.0 * m['mu11'], m['mu20'] - m['mu02'])
print(x_g, y_g, ang * 180.0 / math.pi)

cv2.imshow('src', img_src)  # 入力画像を表示
# cv2.imshow('dst', img_dst) # 出力画像を表示
# cv2.imwrite(file_dst, img_dst) # 処理結果の保存

cv2.waitKey(0)  # キー入力待ち
cv2.destroyAllWindows()
