#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/stitching.hpp>

using namespace cv;
using namespace std;

int main() {
  Mat combine, combine1, combine2;
  Mat a = imread("./video_jpg/1.jpg");
  Mat b = imread("./video_jpg/2.jpg");
  Mat c = imread("./video_jpg/3.jpg");
  Mat d = imread("./video_jpg/4.jpg");
  //水平拼接
  hconcat(a, b, combine1);
  hconcat(c, d, combine2);
  //垂直拼接
  vconcat(combine1, combine2, combine);
  imwrite("./tcp_jpg/combine.jpg", combine);
  return 0;
}
