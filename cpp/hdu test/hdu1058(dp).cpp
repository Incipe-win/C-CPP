#include <bits/stdc++.h>
using namespace std;

#define min(a, b) (a < b ? a : b)

__int64 ans[5900], n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ans[1] = 1;
  int a, b, c, d;
  a = b = c = d = 1;
  for (int i = 2; i <= 5842; i++) {
    ans[i] = min(ans[a] * 2, min(ans[b] * 3, min(ans[c] * 5, ans[d] * 7)));
    if (ans[i] == ans[a] * 2)
      a++;
    if (ans[i] == ans[b] * 3)
      b++;
    if (ans[i] == ans[c] * 5)
      c++;
    if (ans[i] == ans[d] * 7)
      d++;
  }
  while (cin >> n && n) {
    if (n % 10 == 1 && n % 100 != 11) {
      cout << "The " << n << "st humble number is " << ans[n] << "." << endl;
      continue;
    }
    if (n % 10 == 2 && n % 100 != 12) {
      cout << "The " << n << "nd humble number is " << ans[n] << "." << endl;
      continue;
    }
    if (n % 10 == 3 && n % 100 != 13) {
      cout << "The " << n << "rd humble number is " << ans[n] << "." << endl;
      continue;
    }
    cout << "The " << n << "th humble number is " << ans[n] << "." << endl;
  }
  return 0;
}