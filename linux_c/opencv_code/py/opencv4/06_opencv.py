import cv2
import argparse

parse = argparse.ArgumentParser()

parse.add_argument("img_input", help="read one image")
parse.add_argument("img_output", help="save the processed image")

args = vars(parse.parse_args())

img = cv2.imread(args["img_input"])

img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

cv2.imwrite(args["img_output"], img_gray)

cv2.imshow("original image", img)
cv2.imshow("gray image", img_gray)

cv2.waitKey(0)
cv2.destroyAllWindows()
