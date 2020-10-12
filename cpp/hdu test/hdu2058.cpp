#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;
    int a;
    for (int i = 1; i <= n; i++) {
      // a=i;
      if ((2 * a + i - 1) * n / 2 == m) {
        cout << "[" << a << "," << i << "]" << endl;
        a = i;
      }
    }
    cout << endl;
  }
  return 0;
}