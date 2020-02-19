#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, temp = 0;
  int s[1000];
  cin >> n >> m;
  while (m >= n)
    m = m - n;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  for (int i = n - m; i < n; i++) {
    s[n + temp] = s[i];
    temp++;
  }
  for (int i = n - m - 1; i >= 0; --i) {
    s[i + temp] = s[i];
  }
  temp = 0;
  for (int i = 0; i < m; i++) {
    s[i] = s[n + temp];
    temp++;
  }
  for (int i = 0; i < n; i++) {
    if (i == n - 1)
      cout << s[i] << endl;
    else
      cout << s[i] << " ";
  }
  return 0;
}