#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  char s[102], str[1002];
  char words[1002][102];
  while (gets(s)) {
    memset(words, 0, sizeof(words));
    if (strcmp(s, "#") == 0)
      break;
    int m = 0, h = 0, count = 0, j = 0, temp = 0, diff, k, l;
    bool flag = true;
    for (int i = 0; i < strlen(s); i++) {
      if (s[i] == ' ' || s[i + 1] == '\0') {
        if (s[i + 1] == '\0')
          m++;
        for (j; j < m; j++)
          words[h][temp++] = s[j];
        j = m + 1;
        temp = 0;
        h++;
      }
      m++;
    }
    for (k = 1; k < h; k++) {
      diff = 1;
      for (l = 0; l <= k - 1; l++) {
        if (strcmp(words[k], words[l]) == 0) {
          diff = 0;
          break;
        }
      }
      if (diff)
        count++;
    }
    cout << count + 1 << endl;
  }
  return 0;
}