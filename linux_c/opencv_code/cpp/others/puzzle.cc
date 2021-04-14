#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/stitching.hpp>

using namespace std;
using namespace cv;

int main() {
  Mat combine, combine1, combine2;
  Mat a = imread("./flower.jpg");
  Mat b = imread("./flower.jpg");
  Mat c = imread("./flower.jpg");
  Mat d = imread("./flower.jpg");
  //水平拼接
  hconcat(a, b, combine1);
  hconcat(c, d, combine2);

  //垂直拼接
  vconcat(combine1, combine2, combine);
  // namedWindow("Combine", WINDOW_AUTOSIZE);
  // imshow("Combine", combine);
  imwrite("Combine.jpg", combine);
  // cv::waitKey(1);
  return 0;
}
