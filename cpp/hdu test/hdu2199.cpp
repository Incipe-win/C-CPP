#include <bits/stdc++.h>
//#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

double y;
const double EPS = 1e-6;

//#define F(x) 8 * x *x *x *x + 7 * x *x *x + 2 * x *x + 3 * x + 6 - y
//#define F1(x) 32 * x *x *x + 21 * x *x + 4 * x + 3

#define F(x) 8 * x *x *x *x + 7 * x *x *x + 2 * x *x + 3 * x + 6 - y
#define F1(x) 32 * x *x *x + 21 * x *x + 4 * x + 3

double Newton(double x) {
  int k = 1;
  while (fabs(F(x)) > EPS) {
    x -= (F(x)) / (F1(x));
    k++;
    if (k > 30)
      return -1;
  }
  return x;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << std::fixed;
  int T;
  cin >> T;
  while (T--) {
    cin >> y;
    double z;
    bool flag = false;
    for (double i = 0.0; i < 100; i++) {
      z = Newton(i);
      if (z <= 100 && z >= 0) {
        flag = true;
        break;
      }
    }
    if (flag == false) {
      cout << "No solution!" << endl;
    } else {
      cout << std::setprecision(4) << z << endl;
    }
  }
  return 0;
}