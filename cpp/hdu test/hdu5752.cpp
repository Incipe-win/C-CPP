#include <bits/stdc++.h>
using namespace std;
int main() {
  long double n, i;
  while (cin >> n) {
    for (i = 1; i <= 5; i++) {
      n = floor(sqrt(n));
      if (n == 1)
        break;
    }
    if (n == 1) {
      cout << i << endl;
    } else
      cout << "TAT" << endl;
  }
  return 0;
}

/*枚举，暴力AC */