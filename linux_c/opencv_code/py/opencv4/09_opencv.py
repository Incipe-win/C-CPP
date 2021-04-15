import cv2
import argparse

parse = argparse.ArgumentParser()
parse.add_argument("index_camera", help="camera index", type=int)
parse.add_argument("video_output", help="the path to the output video")

args = vars(parse.parse_args())

capture = cv2.VideoCapture(args["index_camera"])

if not capture.isOpened():
    print("camera error")

frame_width = capture.get(cv2.CAP_PROP_FRAME_WIDTH)
frame_height = capture.get(cv2.CAP_PROP_FRAME_HEIGHT)
fps = capture.get(cv2.CAP_PROP_FPS)

# 对视频进行编码
fourcc = cv2.VideoWriter_fourcc(*"XVID")
output_gray = cv2.VideoWriter(args["video_output"], fourcc, int(
    fps), (int(frame_width), int(frame_height)), False)

while capture.isOpened():
    ret, frame = capture.read()
    if ret:
        gray_frame = cv2.cvtColor(frame, cv2.COLOR_RGB2GRAY)
        output_gray.write(gray_frame)
        cv2.imshow("gray_frame", gray_frame)
        if cv2.waitKey(1) & ord('q') == 0xFF:
            break
    else:
        break

capture.release()
output_gray.release()
cv2.destroyAllWindows()
