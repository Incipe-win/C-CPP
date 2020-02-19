#include <bits/stdc++.h>
using namespace std;

#define f(x) (8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6 - y)
#define f1(x) (32 * x * x * x + 21 * x * x + 4 * x + 3)

const double esp = 1e-6;
double y;

double iteration(double x) {
  int tot = 1;
  while (abs(f(x) - 0) > esp) {
    x = x - f(x) / f1(x);
    tot++;
    if (tot > 30)
      return -1;
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  int t;
  cin >> t;
  while (t--) {
    cin >> y;
    bool flag = false;
    double ans = 0;
    for (int i = 0; i < 100; i++) {
      ans = iteration(i);
      if (ans >= 0 && ans <= 100) {
        flag = true;
        break;
      }
    }
    if (flag)
      cout << setprecision(4) << ans << endl;
    else
      cout << "No solution!" << endl;
  }
  return 0;
}