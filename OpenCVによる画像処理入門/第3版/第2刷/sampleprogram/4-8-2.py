import cv2
import math
import numpy as np

cv2.namedWindow('src')
cv2.namedWindow('dst')
cap = cv2.VideoCapture(0)

while True:
    ret, img_src = cap.read()  # カメラ映像の読み込み

    # ここに核となる処理を記述する
    img_dst = cv2.flip(img_src, flipCode = 0)  # 垂直反転

    cv2.imshow('src', img_src)  # 入力画像を表示
    cv2.imshow('dst', img_dst)  # 出力画像を表示
    ch = cv2.waitKey(1)  # キー入力待ち
    if ch == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
