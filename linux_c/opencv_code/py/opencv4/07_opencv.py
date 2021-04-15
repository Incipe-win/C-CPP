import cv2
import argparse

parse = argparse.ArgumentParser()

parse.add_argument("index_camera", help="the camera id", type=int)

args = vars(parse.parse_args())
print("the camera index: ", args["index_camera"])

capture = cv2.VideoCapture(args["index_camera"])

# CAP: capture, PROP: property
frame_width = capture.get(cv2.CAP_PROP_FRAME_WIDTH)
frame_height = capture.get(cv2.CAP_PROP_FRAME_HEIGHT)
# fps: frames per second
fps = capture.get(cv2.CAP_PROP_FPS)
print("frame_width is: {}".format(frame_width))
print("frame_height is: {}".format(frame_height))
print("fps is: {}".format(fps))

if not capture.isOpened():
    print("Camera Error!")

while capture.isOpened():
    ret, frame = capture.read()
    if ret:
        cv2.imshow("frame", frame)
        gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        cv2.imshow("gray frame", gray_frame)
        if cv2.waitKey(20) & 0xFF == ord('q'):
            break
    else:
        break

capture.release()
cv2.destroyAllWindows()
