#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long a, b, n;
    cin >> a >> b >> n;
    switch (n % 3) {
    case 0:
      cout << a << endl;
      break;
    case 1:
      cout << b << endl;
      break;
    default:
      cout << (a ^ b) << endl;
      break;
    }
  }
  return 0;
}