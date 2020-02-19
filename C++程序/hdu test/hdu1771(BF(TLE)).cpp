#include <bits/stdc++.h>
using namespace std;

char str1[1000017], str2[1000017];

int strStr(char *haystack, char *needle) {
  int len1, len2, i = 0, j = 0, count = 0, flag = 0, temp = 0;
  len1 = strlen(haystack);
  len2 = strlen(needle);
  if (len2 == 0)
    return 0;
  if (len1 == 0)
    return -1;
  if (len1 < len2)
    return -1;
  for (i = 0; i < len1; i++) {
    for (j = temp; j < len2; j++) {
      if (haystack[i] == needle[j]) {
        temp++;
        flag++;
        break;
      } else {
        i = count;
        count++;
        temp = 0;
        flag = 0;
        break;
      }
    }
  }
  if (flag == len2)
    return count + 1;
  else
    return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int m1, m2;
    cin >> m1 >> m2;
    // getchar();
    for (int i = 0; i < m1; i++)
      cin >> str1[i];
    for (int i = 0; i < m2; i++)
      cin >> str2[i];
    cout << strStr(str1, str2) << endl;
  }
  return 0;
}