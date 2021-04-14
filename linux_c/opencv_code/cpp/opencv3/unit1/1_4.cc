#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

int main() {
  Mat srcImage = imread("./4.jpg");
  imshow("raw jpg", srcImage);
  Mat dstImage, edge, grayImage;
  dstImage.create(srcImage.size(), srcImage.type());
  cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
  blur(grayImage, edge, Size(3, 3));
  Canny(edge, edge, 3, 9, 3);
  imshow("result jpg", edge);
  waitKey(0);
  return 0;
}
