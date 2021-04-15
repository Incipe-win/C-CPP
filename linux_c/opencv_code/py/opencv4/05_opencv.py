import cv2
import argparse

# img = cv2.imread("./logo.png")
# cv2.imshow("LOGO", img)
# cv2.waitKey(0)
# cv2.destroyAllWindows()

parse = argparse.ArgumentParser()
parse.add_argument("path_image", help="path to input the image")

args = parse.parse_args()

img = cv2.imread(args.path_image)
cv2.imshow("LOGO", img)

args_dict = vars(parse.parse_args())  # {"path_image" : "./logo.png"}
img2 = cv2.imread(args_dict["path_image"])
cv2.imshow("logo_two", img2)
cv2.waitKey(0)

cv2.destroyAllWindows()
