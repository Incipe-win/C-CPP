#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, s, p, flag = 1;
    cin >> n >> m;
    s = (n - 2) * 180 / n;
    p = (m - 2) * 180 / m;
    for (int i = s; i <= (n - 2) * 180 && flag; i += s)
      for (int j = p; j <= (m - 2) * 180 && flag; j += p) {
        if (i + j == 360) {
          cout << "Yes" << endl;
          flag = 0;
        }
      }
    if (flag == 1) {
      if (360 % s == 0 || 360 % p == 0)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
}