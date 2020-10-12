#include <iostream>
using namespace std;
int main() {
  const int PRICE = 30;
  int num, total;
  double v, r, h;
  num = 10;
  total = num * PRICE;
  cout << total << endl;
  r = 2.5;
  h = 3.2;
  v = 3.14159 * r * r * h;
  cout << v << endl;
  return 0;
}