#include <bits/stdc++.h>
using namespace std;
int main() {
  int c;
  cin >> c;
  while (c--) {
    int n, s, r, t, i, j, k;
    cin >> n;
    s = n / 2;
    r = (n - s) * 2 / 3;
    t = n - s - r;
    i = s / 10;
    if (s % 10 != 0)
      i++;
    j = r / 10;
    if (r % 10 != 0)
      j++;
    k = t / 10;
    if (t % 10 != 0)
      k++;
    cout << i + k + j << endl;
  }
  return 0;
}