#include <bits/stdc++.h>
using namespace std;

int strStr(char *haystack, char *needle) {
  int hIndex = 0, nIndex = 0;
  int hLength = strlen(haystack);
  int nLength = strlen(needle);
  if (nLength == 0)
    return 0;

  int res = -1;
  while (hIndex < hLength && nIndex < nLength) {
    if (haystack[hIndex] == needle[nIndex]) {
      if (nIndex == 0)
        res = hIndex;
      hIndex++;
      nIndex++;
    } else {
      hIndex++;
      nIndex = 0;
      if (res != -1) {
        hIndex = res + 1;
        res = -1;
      }
    }
  }
  if (nIndex == nLength)
    return res;
  return -1;
}

int main() {
  char haystack[1000], needle[1000];
  cin >> haystack >> needle;
  int result = strStr(haystack, needle);
  cout << result << endl;
  system("pause");
  return 0;
}
