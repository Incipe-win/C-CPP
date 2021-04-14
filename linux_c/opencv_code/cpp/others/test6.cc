#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
  VideoCapture capture(0);

  while (1) {
    Mat frame;
    capture >> frame;
    imshow("读取视频", frame);
    int k = waitKey(30);
    if (k == 27) {
      break;
    }
  }
  destroyAllWindows();
  return 0;
}
