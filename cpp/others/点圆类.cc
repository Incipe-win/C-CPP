#include <cmath>
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

class Point {
public:
  int getX() { return x; }
  int getY() { return y; }

  void setX(int x) { this->x = x; }

  void setY(int y) { this->y = y; }

private:
  int x;
  int y;
};

class Circle {
public:
  void setR(int r) { this->r = r; }

  int getR() { return r; }

  void setCenter(Point center) { this->center = center; }

  // tuple<int, int> getCenter() {
  //   return make_tuple(center.getX(), center.getY());
  // }

  Point getCenter() { return center; }

  void isInCircleByClass(Point &p) {
    int distance =
        pow((center.getX() - p.getX()), 2) + pow((center.getY() - p.getY()), 2);
    int radius = r * r;
    if (distance == radius) {
      cout << "圆上" << endl;
    } else if (distance < radius) {
      cout << "圆内" << endl;
    } else {
      cout << "圆外" << endl;
    }
  }

private:
  Point center;
  int r;
};

void isInCircle(Circle &c, Point &p) {
  int distance = pow((c.getCenter().getX() - p.getX()), 2) +
                 pow((c.getCenter().getY() - p.getY()), 2);
  int radius = c.getR() * c.getR();
  if (distance == radius) {
    cout << "圆上" << endl;
  } else if (distance < radius) {
    cout << "圆内" << endl;
  } else {
    cout << "圆外" << endl;
  }
}

void test() {
  Point p;
  Circle c;
  p.setX(10);
  p.setY(11);

  c.setR(10);

  Point p1;
  p1.setX(10);
  p1.setY(0);
  c.setCenter(p1);

  isInCircle(c, p);
  c.isInCircleByClass(p);
}

int main() {
  test();
  return 0;
}