#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, a[105], count = 0, j;
  char s;
  a[1] = 1;
  for (int i = 2; i <= 30; i++)
    a[i] = a[i - 1] + 2 * (2 * i - 1);
  cin >> n >> s;
  for (int i = 1; i <= 30; i++) {
    if (a[i] == n) {
      j = i;
      break;
    } else if (a[i] > n) {
      j = i - 1;
      count = n - a[j];
      break;
    }
  }
  for (int i = j; i >= 1; --i) {
    for (int k = j; k > i; --k)
      cout << " ";
    for (int k = 1; k <= 2 * i - 1; k++)
      cout << s;
    cout << endl;
  }
  for (int i = 2; i <= j; i++) {
    for (int k = j; k > i; --k)
      cout << " ";
    for (int k = 1; k <= 2 * i - 1; k++)
      cout << s;
    cout << endl;
  }
  cout << count << endl;
  return 0;
}