import cv2
import argparse

parse = argparse.ArgumentParser()
parse.add_argument("video_path", help="the path to the video file")

args = vars(parse.parse_args())

capture = cv2.VideoCapture(args["video_path"])

# ret是否读取到了帧（图片）
ret, frame = capture.read()

while ret:
    cv2.imshow("video", frame)
    ret, frame = capture.read()
    if cv2.waitKey(20) & ord('q') == 0xFF:
        break

capture.release()
cv2.destroyAllWindows()
