#include <bits/stdc++.h>
using namespace std;

struct node {
  double x;
  double y;
} point[120];

double Area(node a, node b, node c) {
  double temp =
      (a.x * b.y + c.x * a.y + b.x * c.y) - (a.x * c.y + b.x * a.y + c.x * b.y);
  return temp;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  int T;
  cin >> T;
  while (T--) {
    int n;
    double maxn = 99999999;
    bool flag = false;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> point[i].x >> point[i].y;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        for (int k = j + 1; k < n; k++) {
          double t = Area(point[i], point[j], point[k]);
          if (t < 0)
            t = -t;
          if (maxn > t && t != 0) {
            maxn = t;
            flag = true;
          }
        }
    if (flag) {
      cout << setprecision(2) << (double)maxn / 2 << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }
  return 0;
}