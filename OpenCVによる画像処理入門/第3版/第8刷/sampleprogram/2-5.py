import cv2
from google.colab.patches import cv2_imshow
# 関数 imread で画像を読み込み
cv_img = cv2.imread('sample.jpg')

# 代替関数 cv2_imshow で表示
cv2_imshow(cv_img)
