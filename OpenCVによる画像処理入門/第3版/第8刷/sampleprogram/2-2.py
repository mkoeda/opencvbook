import cv2
import numpy as np
img = np.zeros((480, 640)).astype(np.uint8)
cv2.imshow('src', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
