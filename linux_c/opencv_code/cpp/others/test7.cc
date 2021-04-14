#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
  VideoCapture capture(0);
  Mat edges;

  while (1) {
    Mat frame;
    capture >> frame;
    cvtColor(frame, edges, COLOR_BGR2GRAY);
    blur(edges, edges, Size(7, 7));

    Canny(edges, edges, 0, 30, 3);
    imshow("被canny后的视频", edges);
    waitKey(30);
  }
  return 0;
}
