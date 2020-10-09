#include <bits/stdc++.h>
using namespace std;

string add(string s1, string s2) {
  if (s1 == "" && s2 == "")
    return "0";
  if (s1 == "")
    return s2;
  if (s2 == "")
    return s1;
  string max, min;
  int len1 = s1.length(), len2 = s2.length();
  if (len1 > len2) {
    max = s1;
    min = s2;
  } else {
    max = s2;
    min = s1;
  }
  int maxlen = max.length(), minlen = min.length();
  int i, j;
  for (i = maxlen - 1, j = minlen - 1; j >= 0; --j, --i) {
    max[i] = max[i] + min[j] - '0';
  }
  for (i = maxlen - 1; i > 0; i--) {
    if (max[i] > '9') {
      max[i] = max[i] - 10;
      max[i - 1] += 1;
    }
  }
  if (max[0] > '9') {
    max[0] = max[0] - 10;
    max = "1" + max;
  }
  return max;
}

int main() {
  string c1, c2, c3;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c1 >> c2;
    cout << "Case " << i << ":" << endl;
    cout << c1 << " + " << c2 << " = " << add(c1, c2) << endl;
    if (i != n)
      cout << endl;
  }
  return 0;
}
