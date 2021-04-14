#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
  VideoCapture capture(0);

  while (1) {
    Mat frame;
    capture >> frame;
    imshow("show", frame);
    waitKey(1);
  }
  return 0;
}
