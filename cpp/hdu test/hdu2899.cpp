#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

double y;
const double EPS = 1e-8, INF = 0x3f3f3f3f;

double f2(double x) {
  return 42 * 6 * pow(x, 5) + 48 * 5 * pow(x, 4) + 21 * 2 * pow(x, 1) + 10;
}
double f1(double x) {
  return 42 * pow(x, 6) + 48 * pow(x, 5) + 21 * pow(x, 2) + 10 * pow(x, 1) - y;
}
double f(double x) {
  return 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) + 5 * pow(x, 2) - y * x;
}

double Newton(double x) {
  int k = 0;
  while (fabs(f1(x)) > EPS) {
    x -= (f1(x)) / (f2(x));
    if (++k > 50)
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
    double temp, z;
    temp = INF;
    for (double i = 0.0; i < 100; i++) {
      z = Newton(i);
      if (z >= 0 && z <= 100) {
        temp = std::min(temp, f(z));
      }
    }
    cout << std::setprecision(4) << temp << endl;
  }
  return 0;
}