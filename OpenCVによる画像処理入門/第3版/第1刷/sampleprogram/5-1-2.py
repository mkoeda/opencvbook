import cv2
import math
import numpy as np

file_src = 'src.png'
file_dst = 'dst.png'

img_src = cv2.imread(file_src, 1)

cv2.namedWindow('src')
cv2.namedWindow('dst')

# 複数色チャンネルの分割
img_bgr = cv2.split(img_src)
# 青→赤，緑→青，赤→緑に変更
img_dst = cv2.merge((img_bgr[1], img_bgr[2], img_bgr[0]))

cv2.imshow('src', img_src)  # 入力画像を表示
cv2.imshow('dst', img_dst)  # 出力画像を表示
cv2.imwrite(file_dst, img_dst)  # 処理結果の保存

cv2.waitKey(0)  # キー入力待ち
cv2.destroyAllWindows()
