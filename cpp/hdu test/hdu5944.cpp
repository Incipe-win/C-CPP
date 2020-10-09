#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    char s[100017];
    cin >> s + 1;
    int n = strlen(s + 1), count = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 2; j <= n; j++) {
        if (i * j <= n && i * j * j <= n) {
          if ((s[i] == 'y' && s[i * j] == 'r' && s[i * j * j] == 'x') ||
              (s[i] == 'x' && s[i * j] == 'r' && s[i * j * j] == 'y')) {
            count++;
          }
        } else
          break;
      }
    }
    cout << count << endl;
  }
  return 0;
}