#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {
  Mat srcImage = imread("./2.jpg");
  imshow("raw jpg", srcImage);
  Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
  Mat dstImage;
  erode(srcImage, dstImage, element);
  imshow("result jpg", dstImage);
  waitKey(0);
  return 0;
}
