import cv2
import math
import numpy as np

file_src = 'src.png'
file_dst = 'dst.png'
file_hst = 'hst.png'

img_src = cv2.imread(file_src, 0)

cv2.namedWindow('src')
cv2.namedWindow('dst')
cv2.namedWindow('hst')

img_dst = 255 - img_src

# ヒストグラム表示用，256×100ピクセル，0で初期化
img_hst = np.zeros([100, 256]).astype('uint8')
rows, cols = img_hst.shape

# 度数分布を求める
hdims = [256]
hranges = [0, 256]
hist = cv2.calcHist([img_dst], [0], None, hdims, hranges)

# 度数の最大値を取得
min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(hist)

for i in range(0, 255):
  v = hist[i]
  cv2.line(img_hst, (i, rows), (i, int(rows - rows * (v / max_val))), (255, 255, 255))

cv2.imshow('src', img_src)  # 入力画像を表示
cv2.imshow('dst', img_dst)  # 出力画像を表示
cv2.imshow('hst', img_hst)  # 出力画像を表示
cv2.imwrite(file_dst, img_dst)  # 処理結果の保存
cv2.imwrite(file_hst, img_hst)  # 処理結果の保存

cv2.waitKey(0)  # キー入力待ち
cv2.destroyAllWindows()
