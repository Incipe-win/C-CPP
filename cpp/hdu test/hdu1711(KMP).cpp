#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int b[10010];
int next1[10010];

void Getnext(int len) {
  int i = 0, j = -1;
  next1[0] = -1;
  while (i < len) {
    if (j == -1 || b[i] == b[j]) {
      i++;
      j++;
      next1[i] = j;
    } else
      j = next1[j];
  }
}

int KMP(int n, int m) {
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (j == -1 || a[i] == b[j]) {
      i++;
      j++;
    } else
      j = next1[j];
  }
  if (j == m)
    return i - j + 1;
  else
    return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  int n, m;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < m; i++)
      cin >> b[i];
    Getnext(m);
    cout << KMP(n, m) << endl;
  }
  return 0;
}