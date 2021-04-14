#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
  Mat srcImage = imread("./fruit.jpg", 1);
  imshow("原图Canny边缘检测", srcImage);
  Mat dstImage, edge, grayImage;
  dstImage.create(srcImage.size(), srcImage.type());
  cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
  blur(grayImage, edge, Size(3, 3));
  Canny(edge, edge, 3, 9, 3);
  imshow("效果图Canny边缘检测", edge);
  int k = waitKey(0);
  if (k == 27) {
    destroyAllWindows();
  }
  return 0;
}
