#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main() {
  Mat girl = imread("./girl.jpg");
  namedWindow("[1]动漫图");
  imshow("[1]动漫图", girl);

  Mat image = imread("./dota.jpg", 1);
  Mat logo = imread("./dota_logo.jpg");
  namedWindow("[2]原画图");
  imshow("[2]原画图", image);
  namedWindow("[3]logo图");
  imshow("[3]logo图", logo);
  Mat imageROI;
  imageROI = image(Rect(800, 350, logo.cols, logo.rows));
  // imageROI = image(Range(350, 350 + logo.rows), Range(800, 800 + logo.cols));
  addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);
  namedWindow("[4]原画+logo图");
  imshow("[4]原画+logo图", image);
  imwrite("有imwrite生成的图片.jpg", image);
  waitKey();
  return 0;
}
