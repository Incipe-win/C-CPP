import matplotlib.pyplot as plt
import cv2

img_logo = cv2.imread("./logo.png")

b, g, r = cv2.split(img_logo)

img_new = cv2.merge([r, g, b])

# plt.subplot(121)
# plt.imshow(img_logo)
# plt.subplot(122)
# plt.imshow(img_new)
#
# plt.show()

cv2.imshow("bgr_image", img_logo)
cv2.imshow("rgb_image", img_new)
cv2.waitKey(0)
cv2.destroyAllWindows()
