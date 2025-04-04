import cv2
import math
import numpy as np

file_src = 'src.png'
file_dst1 = 'dst1.png'
file_dst2 = 'dst2.png'

img_src = cv2.imread(file_src, cv2.IMREAD_COLOR)

cv2.namedWindow('src')
cv2.namedWindow('dst1')
cv2.namedWindow('dst2')

img_dst1 = cv2.GaussianBlur(img_src, (11, 11), 1) # Gaussian オペレータ
img_dst2 = cv2.bilateralFilter(img_src, 10, 50, 1) # バイラテラルオペレータ

cv2.imshow('src', img_src)  # 入力画像を表示
cv2.imshow('dst1', img_dst1)  # 出力画像を表示
cv2.imshow('dst2', img_dst2)  # 出力画像を表示
cv2.imwrite(file_dst1, img_dst1)  # 処理結果の保存
cv2.imwrite(file_dst2, img_dst2)  # 処理結果の保存

cv2.waitKey(0)  # キー入力待ち
cv2.destroyAllWindows()
