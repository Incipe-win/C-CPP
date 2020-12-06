#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
  Mat img = cv::imread("./flower.jpg", 1);
  imshow("open a pic", img);
  int k = waitKey(0);
  if (k == 27) {
    destroyAllWindows();
  }
  return 0;
}
