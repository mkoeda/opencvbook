import cv2
import math
import numpy as np

file_src = 'src.png'
file_dst = 'dst.png'

img_src = cv2.imread(file_src, 1)
# img_src = cv2.imread(file_src, 0) # 入力画像（グレースケール）の読み込み

cv2.namedWindow('src')
cv2.namedWindow('dst')

# ここに核となる処理を記述する
img_dst = cv2.flip(img_src, flipCode=0)  # 垂直反転

cv2.imshow('src', img_src)  # 入力画像を表示
cv2.imshow('dst', img_dst)  # 出力画像を表示
cv2.imwrite(file_dst, img_dst)  # 処理結果の保存
cv2.waitKey(0)  # キー入力待ち
cv2.destroyAllWindows()
