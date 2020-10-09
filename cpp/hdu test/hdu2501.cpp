#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    __int64 ans[35];
    ans[2] = 3;
    ans[3] = 5;
    for (int i = 4; i <= num; i++) {
      ans[i] = 2 * ans[i - 2] + ans[i - 1];
    }
    cout << ans[num] << endl;
  }
  return 0;
}