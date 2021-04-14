#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main() {
  Mat srcImage = imread("./flower.jpg", 1);
  imshow("原图腐蚀操作", srcImage);
  Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
  Mat dstImage;
  erode(srcImage, dstImage, element);
  imshow("效果图腐蚀操作", dstImage);
  int k = waitKey(0);
  if (k == 27) {
    destroyAllWindows();
  }
  return 0;
}
