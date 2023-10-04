import cv2
# matplotlib ライブラリの関数を利用するためのインポート
from matplotlib import pyplot as plt
# 画像ファイルの読み込み
cv_img = cv2.imread('sample.jpg')
# 画像の色情報を BGR から RGB の順番に変換
src = cv2.cvtColor(cv_img, cv2.COLOR_BGR2RGB)

# 画像ファイルの表示
plt.imshow(src)
