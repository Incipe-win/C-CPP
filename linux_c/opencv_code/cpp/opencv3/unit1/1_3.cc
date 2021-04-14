#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main() {
  Mat srcImage = imread("./3.jpg");
  imshow("raw jpg", srcImage);
  Mat dstImage;
  blur(srcImage, dstImage, Size(7, 7));
  imshow("result.jpg", dstImage);
  waitKey(0);
  return 0;
}
