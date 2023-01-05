import cv2
import math
import numpy as np

file_src = 'src.png'
file_dst = 'dst.png'

img_src = cv2.imread(file_src, 1)

cv2.namedWindow('src')
cv2.namedWindow('dst')

size = tuple(np.array([img_src.shape[1], img_src.shape[0]]))

pts1 = np.float32([[0, 0], [0, 479], [639, 479], [639, 0]])
pts2 = np.float32([[160, 240], [0, 479], [639, 479], [480, 240]])

psp_mat = cv2.getPerspectiveTransform(pts1, pts2)

img_dst = cv2.warpPerspective(img_src, psp_mat, size)

cv2.imshow('src', img_src)  # 入力画像を表示
cv2.imshow('dst', img_dst)  # 出力画像を表示
cv2.imwrite(file_dst, img_dst)  # 処理結果の保存

cv2.waitKey(0)  # キー入力待ち
cv2.destroyAllWindows()
