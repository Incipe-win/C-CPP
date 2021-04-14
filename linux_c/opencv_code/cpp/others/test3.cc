#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main() {
  Mat srcImage = imread("./flower.jpg", 1);
  imshow("均值滤波原图", srcImage);
  Mat dstImage;
  blur(srcImage, dstImage, Size(7, 7));
  imshow("均值滤波效果图", dstImage);
  int k = waitKey(0);
  if (k == 27) {
    destroyAllWindows();
  }
  return 0;
}
