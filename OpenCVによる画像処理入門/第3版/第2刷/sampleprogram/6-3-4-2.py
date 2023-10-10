import cv2
import numpy as np

def nothing(x):
  pass

# 画像読み込み
file_src = 'src.png'
img_src = cv2.imread(file_src, cv2.IMREAD_COLOR)
# ウインドウ生成
cv2.namedWindow('src')
cv2.namedWindow('dst')
# トラックバーの生成
cv2.createTrackbar('gamma', 'dst', 1, 10, nothing)
# 入力画像を表示
cv2.imshow('src', img_src)

while True:
  # トラックバーの値を取得
  gamma = cv2.getTrackbarPos('gamma', 'dst') + 1.0

  # ガンマ補正
  Y = np.ones((256, 1), dtype = 'uint8') * 0
  for i in range(256):
    Y[i][0] = 255 * pow(float(i) / 255, 1.0 / gamma)
  img_dst = cv2.LUT(img_src, Y)

  # 出力画像を表示
  cv2.imshow('dst', img_dst)
  # qキーで終了
  key = cv2.waitKey(1)
  if key & 0xFF == ord('q'):
    break

cv2.destroyAllWindows()
