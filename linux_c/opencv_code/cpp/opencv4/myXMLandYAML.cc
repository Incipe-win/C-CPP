#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
  // string fileName = "datas.yaml";
  string fileName = "datas.xml";
  FileStorage fwrite(fileName, FileStorage::WRITE);
  Mat mat = Mat::eye(3, 3, CV_8U);
  fwrite.write("mat", mat);
  float x = 100;
  fwrite << "x" << x;
  String str = "Learn Opencv 4";
  fwrite << "str" << str;
  fwrite << "number_array"
         << "[" << 4 << 5 << 6 << "]";
  fwrite << "multi_nodes"
         << "{"
         << "month" << 8 << "day" << 28 << "year" << 2019 << "time"
         << "[" << 0 << 1 << 2 << 3 << "]"
         << "}";
  fwrite.release();

  FileStorage fread(fileName, FileStorage::READ);
  if (!fread.isOpened()) {
    cout << "file open error" << endl;
    return -1;
  }
  float xRead;
  fread["x"] >> xRead;
  cout << "x=" << xRead << endl;
  string strRead;
  fread["str"] >> strRead;
  cout << "str=" << strRead << endl;
  FileNode fileNode = fread["number_array"];
  cout << "number_array=[";
  for (const auto &it : fileNode) {
    float a;
    it >> a;
    cout << a << " ";
  }
  cout << "]" << endl;
  Mat matRead;
  fread["mat="] >> matRead;
  cout << "mat=" << mat << endl;

  FileNode fileNode1 = fread["multi_nodes"];
  int month = (int)fileNode1["month"];
  int day = (int)fileNode1["day"];
  int year = (int)fileNode1["year"];
  cout << "multi_nodes:" << endl
       << "  month=" << month << "  day=" << day << "  year=" << year;
  cout << "  time=[";
  for (int i = 0; i < 4; ++i) {
    int a = (int)fileNode1["time"][i];
    cout << a << " ";
  }
  cout << "]" << endl;
  fread.release();
  return 0;
}
