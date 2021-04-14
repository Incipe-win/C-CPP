#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
  Mat srcImage = imread("./1.jpg");
  imshow("show", srcImage);
  waitKey(0);
  return 0;
}
