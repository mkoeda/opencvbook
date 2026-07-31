import cv2
import math
import numpy as np

file_src = 'src_bin.png'
file_dst = 'dst.png'

img_src = cv2.imread(file_src, cv2.IMREAD_GRAYSCALE)

cv2.namedWindow('src')
# cv2.namedWindow('dst')

rows, cols = img_src.shape
print(rows, cols)

x, y, w, h = cv2.boundingRect(img_src)
aspectratio = float(h) / w
print(aspectratio)
cv2.rectangle(img_src, (x, y), (x + w, y + h), 128)

cv2.imshow('src', img_src)  # 入力画像を表示
# cv2.imshow('dst', img_dst) # 出力画像を表示
# cv2.imwrite(file_dst, img_dst) # 処理結果の保存

cv2.waitKey(0)  # キー入力待ち
cv2.destroyAllWindows()
