#include <bits/stdc++.h>
using namespace std;

__int64 ans[5900];

bool IsUgly(int num) {
  if (num == 0)
    return false;
  while (num % 2 == 0)
    num /= 2;
  while (num % 3 == 0)
    num /= 3;
  while (num % 5 == 0)
    num /= 5;
  while (num % 7 == 0)
    num /= 7;
  return num == 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, count, temp;
  while (cin >> n && n) {
    count = 0;
    for (int i = 1;; i++) {
      if (IsUgly(i))
        count++;
      if (count == n) {
        temp = i;
        break;
      }
    }
    if (n % 10 == 1 && n % 100 != 11) {
      cout << "The " << n << "st humble number is " << temp << endl;
      continue;
    }
    if (n % 10 == 2 && n % 100 != 12) {
      cout << "The " << n << "nd humble number is " << temp << endl;
      continue;
    }
    if (n % 10 == 3 && n % 100 != 13) {
      cout << "The " << n << "rd humble number is " << temp << endl;
      continue;
    }
    cout << "The " << n << "th humble number is " << temp << endl;
  }
  return 0;
}