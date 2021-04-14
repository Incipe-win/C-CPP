import cv2

img = cv2.imread("./flower.jpg")
print(img.shape)
img_dtype = img.dtype
print(img_dtype)

(b, g, r) = img[6, 40]
print(b, g, r)

b = img[6, 40, 0]
g = img[6, 40, 1]
r = img[6, 40, 2]
print(b, g, r)

cv2.imshow("raw", img)
img[6, 40] = (0, 0, 255)
cv2.imshow("change", img)
cv2.waitKey(0)
