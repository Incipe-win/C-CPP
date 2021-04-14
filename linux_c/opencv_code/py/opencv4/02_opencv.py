import cv2

gray_img = cv2.imread("./gray.png", cv2.IMREAD_GRAYSCALE)
print(gray_img.shape)
value = gray_img[6, 40]
print(value)
