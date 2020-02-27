#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int a;
  string tmp;
  cin >> a;
  if (a == 0) {
    cout << a << endl;
  } else {
    while (a) {
      if (a % 16 == 10) {
        tmp += "A";
      } else if (a % 16 == 11) {
        tmp += "B";
      } else if (a % 16 == 12) {
        tmp += "C";
      } else if (a % 16 == 13) {
        tmp += "D";
      } else if (a % 16 == 14) {
        tmp += "E";
      } else if (a % 16 == 15) {
        tmp += "F";
      } else {
        tmp += (a % 16 + '0');
      }
      a /= 16;
    }
    reverse(tmp.begin(), tmp.end());
    cout << tmp << endl;
  }
  return 0;
}