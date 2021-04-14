#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void AlphaMat(Mat &mat) {
  CV_Assert(mat.channels() == 4);
  for (int i = 0; i < mat.rows; ++i) {
    for (int j = 0; j < mat.cols; ++j) {
      Vec4b &bgra = mat.at<Vec4b>(i, j);
      bgra[0] = UCHAR_MAX;
      bgra[1] = saturate_cast<uchar>((float(mat.cols - j)) / ((float)mat.cols) *
                                     UCHAR_MAX);
      bgra[2] = saturate_cast<uchar>((float(mat.rows - i)) / ((float)mat.rows) *
                                     UCHAR_MAX);
      bgra[3] = saturate_cast<uchar>(0.5 * (bgra[1] + bgra[2]));
    }
  }
}

int main() {
  Mat mat(480, 640, CV_8UC4);
  AlphaMat(mat);
  vector<int> compression_params;
  compression_params.emplace_back(IMWRITE_PNG_COMPRESSION);
  compression_params.emplace_back(9);
  bool result = imwrite("alpha.png", mat, compression_params);
  if (!result) {
    cout << "save png fault" << endl;
    return -1;
  }
  cout << "save sucess" << endl;
  return 0;
}
