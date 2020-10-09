#include <cstring>
#include <iostream>

char a[100017], b[100017];

using std::cin;
using std::cout;
using std::endl;

void De(char *s) {
  int len = strlen(s);
  // for (int i = 0; i < len; i++) {
  //   if (s[i] == '0') {
  //     for (int j = i; j < len; j++)
  //       s[j] = s[j + 1];
  //     len--;
  //     // s[len - 1] = '\0';
  //   }
  // }
  char *p;
  p = s;
  bool flag = false;
  while (*p) {
    if (*p == '.') {
      flag = true;
      break;
    }
    p++;
  }
  if (flag) {
    for (int i = len - 1; i >= 0; i--) {
      if (s[i] == '0')
        s[i] = '\0';
      else
        break;
      len--;
    }
    if (s[len - 1] == '.')
      s[len - 1] = '\0';
  }
}

int main() {
  while (cin >> a >> b) {
    De(a);
    De(b);
    if (strcmp(a, b) == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}