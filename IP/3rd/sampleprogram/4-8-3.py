import cv2

file_src = 'src.png'
img_gray = cv2.imread(file_src, 0)
img_src = cv2.imread(file_src, 1)
cv2.namedWindow('gray')
cv2.namedWindow('src')

x = 10
y = 50
v = 255
r = 255
g = 255
b = 0

# グレースケール画像の場合
print(img_gray[y, x])
img_gray[y, x] = v
print(img_gray[y, x])

# カラー画像の場合
print(img_src[y, x])
img_src[y, x] = [b, g, r]
print(img_src[y, x])

cv2.imshow('gray', img_gray)
cv2.imshow('src', img_src)
cv2.waitKey(0)
cv2.destroyAllWindows()
