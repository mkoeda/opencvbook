import cv2
import numpy as np

# 640x480の黒い画像
img_src = np.zeros((480, 640, 3), np.uint8)

# 点(0, 0)と点(640, 480)を結ぶ太さ5の黄色の線分
cv2.line(img_src, (0, 0), (640, 480), (0, 255, 255), 5)
# 点(200, 50)と点(300, 50)を結ぶ太さ5の黄色の矢印
cv2.arrowedLine(img_src, (200, 50), (300, 50), (0, 255, 255), 5)
# 左上座標(100, 150)，幅50，高さ150，太さ2の赤色の矩形
cv2.rectangle(img_src, (100, 150, 50, 150), (0, 0, 255), 2)
# 左上座標(50, 350)，幅200，高さ50，塗りつぶしの赤色の矩形
cv2.rectangle(img_src, (50, 350, 200, 50), (0, 0, 255), -1)
# 中心座標(320, 240)，半径100，太さ3の青色の円
cv2.circle(img_src, (320, 240), 100, (255, 0, 0), 3)
# 中心座標(500, 100)，半径50，塗りつぶしの青色の円
cv2.circle(img_src, (500, 100), 50, (255, 0, 0), -1)
# 中心座標(550, 250)，幅100，高さ50，太さ3の45度傾いた青色の楕円
cv2.ellipse(img_src, ((550, 250), (100, 50), 45), (255, 0, 0), 3)
# 中心座標(550, 250)，長径100，短径50，太さ3の45度傾いた青色の半円
cv2.ellipse(img_src, (550, 250), (100, 50), 45, 0, 180, (255, 0, 0), 3)
# 左下座標(300, 450), 倍率3，太さ5の水色の文字列123
cv2.putText(img_src, "123", (300, 450), 0, 3, (255, 255, 0), 5)
# 様々な形状の大きさ10，太さ2の緑色のマーカ
cv2.drawMarker(img_src, (50, 20), (0, 255, 0), cv2.MARKER_CROSS, 10, 2)
cv2.drawMarker(img_src, (70, 20), (0, 255, 0), cv2.MARKER_TILTED_CROSS, 10, 2)
cv2.drawMarker(img_src, (90, 20), (0, 255, 0), cv2.MARKER_STAR, 10, 2)
cv2.drawMarker(img_src, (110, 20), (0, 255, 0), cv2.MARKER_DIAMOND, 10, 2)
cv2.drawMarker(img_src, (130, 20), (0, 255, 0), cv2.MARKER_SQUARE, 10, 2)
cv2.drawMarker(img_src, (150, 20), (0, 255, 0), cv2.MARKER_TRIANGLE_UP, 10, 2)
cv2.drawMarker(img_src, (170, 20), (0, 255, 0), cv2.MARKER_TRIANGLE_DOWN, 10, 2)

# 表示
cv2.namedWindow('src')
cv2.imshow('src', img_src)
# キー入力待ち
cv2.waitKey(0)

cv2.destroyAllWindows()
