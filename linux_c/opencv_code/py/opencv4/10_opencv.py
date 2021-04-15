import cv2
import matplotlib.pyplot as plt
import numpy as np

rows, cols = 5, 5

img = cv2.imread("./logo.png")
plt.subplot(rows, cols, 1)
plt.imshow(img)

height, width, channel = img.shape
print(height, width, channel)

# 放大
resized_img = cv2.resize(img, (width * 2, height * 2),
                         interpolation=cv2.INTER_LINEAR)
plt.subplot(rows, cols, 2)
plt.imshow(resized_img)

# 缩小
small_img = cv2.resize(img, None, fx=0.5, fy=0.5,
                       interpolation=cv2.INTER_LINEAR)
plt.subplot(rows, cols, 3)
plt.imshow(small_img)

height, width = img.shape[:2]
# 平移 平移矩阵 上下平移
M1 = np.float32([[1, 0, 100], [0, 1, 50]])
move_img = cv2.warpAffine(img, M1, (width, height))
plt.subplot(rows, cols, 4)
plt.imshow(move_img)

# 左右平移
M2 = np.float32([[1, 0, -100], [0, 1, -50]])
move_img2 = cv2.warpAffine(img, M2, (width, height))
plt.subplot(rows, cols, 5)
plt.imshow(move_img2)

# 旋转
height, width = img.shape[:2]
center = (width // 2, height // 2)
M3 = cv2.getRotationMatrix2D(center, 180, 1)
rotation_img = cv2.warpAffine(img, M3, (width, height))
plt.subplot(rows, cols, 6)
plt.imshow(rotation_img)

# 仿射变换
p1 = np.float32([[120, 35], [215, 45], [135, 120]])
p2 = np.float32([[135, 45], [300, 110], [130, 230]])
M4 = cv2.getAffineTransform(p1, p2)
trans_img = cv2.warpAffine(img, M4, (width, height))
plt.subplot(rows, cols, 7)
plt.imshow(trans_img)

# 裁剪
crop_img = img[20:500, 200:400]
plt.subplot(rows, cols, 8)
plt.imshow(crop_img)

# 位运算
rectangle = np.zeros((300, 300), dtype='uint8')
rect_img = cv2.rectangle(rectangle, (25, 25), (275, 275), 255, -1)
plt.subplot(rows, cols, 9)
plt.imshow(rect_img)

circle = np.zeros((300, 300), dtype="uint8")
circle_img = cv2.circle(circle, (150, 150), 150, 255, -1)
plt.subplot(rows, cols, 10)
plt.imshow(circle_img)

# 与运算
and_img = cv2.bitwise_and(rect_img, circle_img)
plt.subplot(rows, cols, 11)
plt.imshow(and_img)

or_img = cv2.bitwise_or(rect_img, circle_img)
plt.subplot(rows, cols, 12)
plt.imshow(or_img)

not_img = cv2.bitwise_not(rect_img, circle_img)
plt.subplot(rows, cols, 13)
plt.imshow(not_img)

xor_img = cv2.bitwise_xor(rect_img, circle_img)
plt.subplot(rows, cols, 14)
plt.imshow(xor_img)

# 图像分离和融合
(B, G, R) = cv2.split(img)
plt.subplot(rows, cols, 15)
plt.imshow(B)

plt.subplot(rows, cols, 16)
plt.imshow(G)

plt.subplot(rows, cols, 17)
plt.imshow(R)

zeros = np.zeros(img.shape[:2], dtype="uint8")
plt.subplot(rows, cols, 18)
plt.imshow(cv2.merge([zeros, zeros, R]))

plt.subplot(rows, cols, 19)
plt.imshow(cv2.merge([G, zeros, zeros]))

plt.subplot(rows, cols, 20)
plt.imshow(cv2.merge([zeros, B, zeros]))

# 颜色空间
# 灰度
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
plt.subplot(rows, cols, 21)
plt.imshow(gray)
# HSV(色度, 饱和度, 纯度)
hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
plt.subplot(rows, cols, 22)
plt.imshow(hsv)
# Lab
lab = cv2.cvtColor(img, cv2.COLOR_BGR2Lab)
plt.subplot(rows, cols, 23)
plt.imshow(lab)

plt.show()
