#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while (cin >> n) {
    ll ans[36];
    ans[1] = 2;
    for (int i = 2; i <= n; i++)
      ans[i] = 3 * ans[i - 1] + 2;
    cout << ans[n] << endl;
  }
  return 0;
}