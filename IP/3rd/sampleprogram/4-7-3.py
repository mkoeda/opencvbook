import cv2
import math
import numpy as np
import sys

cap = cv2.VideoCapture(0)  # カメラオープン
if not cap.isOpened():
  print('error')
  sys.exit()

# ウインドウ生成
cv2.namedWindow('src')

# 解像度の設定
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

# 解像度の確認
ret, img_src = cap.read()
print(img_src.shape[1], img_src.shape[0])

while True:
  ret, img_src = cap.read()  # キャプチャ
  cv2.imshow('src', img_src)  # 表示
  key = cv2.waitKey(1)
  if key == ord('q'):
    break

cap.release()
cv2.destroyAllWindows()
