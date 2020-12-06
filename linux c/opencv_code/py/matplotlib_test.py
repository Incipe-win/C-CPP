import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt

img = cv.imread("./flower.jpg", 1)
img = cv.cvtColor(img, cv.COLOR_BGR2RGB)
plt.imshow(img, cmap='gray', interpolation='bicubic')
plt.xticks([])
plt.yticks([])
plt.show()
