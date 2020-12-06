# -*- coding:utf-8 -*-

import numpy as np
import cv2


img = np.zeros((512, 512, 3), np.uint8)

# 上－外圆－红色填充
img = cv2.circle(img, (256, 176), 40, (0, 0, 255), -1)
# 上－内圆－黑色填充
img = cv2.circle(img, (256, 176), 16, (0, 0, 0), -1)

# 左下－外圆－绿色填充
img = cv2.circle(img, (210, 256), 40, (0, 255, 0), -1)
# 左下－内圆－黑色填充
img = cv2.circle(img, (210, 256), 16, (0, 0, 0), -1)

# 右下－外圆－蓝色填充
img = cv2.circle(img, (302, 256), 40, (255, 0, 0), -1)
# 右下－内圆－黑色填充
img = cv2.circle(img, (302, 256), 16, (0, 0, 0), -1)


# 用一个四角的多边形来填充覆盖
pts = np.array([[256, 176], [210, 256], [250, 256], [276, 210]], np.int32)
pts = pts.reshape((-1, 1, 2))
img = cv2.fillPoly(img, [pts], (0, 0, 0))

# 第2个覆盖，使用三角形
pts2 = np.array([[276, 210], [302, 256], [322, 210]], np.int32)
pts2 = pts2.reshape((-1, 1, 2))
img = cv2.fillPoly(img, [pts2], (0, 0, 0))

cv2.imshow('draw exercise', img)
cv2.waitKey()
cv2.destroyAllWindows()
