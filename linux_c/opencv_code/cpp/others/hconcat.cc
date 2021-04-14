#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
  Mat img1 = imread("1.png");
  Mat img2 = imread("2.png");
  vector<Mat> vImgs;
  Mat result;
  vImgs.push_back(img1);
  vImgs.push_back(img2);
  // vconcat(vImgs, result);  //垂直方向拼接
  hconcat(vImgs, result);  //水平方向拼接
  imwrite("result.jpg", result);
  return 0;
}
