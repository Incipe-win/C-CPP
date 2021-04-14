#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
  Mat img;
  VideoCapture video(0);
  if (!video.isOpened()) {
    cout << "opencv video error" << endl;
    return -1;
  }
  video >> img;
  if (img.empty()) {
    cout << "hasn't video" << endl;
    return -1;
  }
  bool isColor = (img.type() == CV_8UC3);
  VideoWriter writer;
  int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
  double fps = 25.0;
  string filename = "live.avi";
  writer.open(filename, codec, fps, img.size(), isColor);

  if (!writer.isOpened()) {
    cout << "open video error" << endl;
    return -1;
  }
  while (1) {
    if (!video.read(img)) {
      cout << "video disable or vedio had readed" << endl;
      break;
    }
    writer.write(img);
    imshow("Live", img);
    char c = waitKey(50);
    if (c == 27) {
      break;
    }
  }
  return 0;
}
