#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::map<std::string, int> mp;
  mp["zero"] = 0;
  mp["one"] = 1;
  mp["two"] = 2;
  mp["three"] = 3;
  mp["four"] = 4;
  mp["five"] = 5;
  mp["six"] = 6;
  mp["seven"] = 7;
  mp["eight"] = 8;
  mp["nine"] = 9;
  std::string s;
  int sum1, sum2;
  bool flag = false;
  sum1 = sum2 = 0;
  while (cin >> s) {
    if (s[0] == '=') {
      if (sum1 == 0 && sum2 == 0)
        break;
      printf("%d\n", sum1 + sum2);
      flag = false;
      sum1 = sum2 = 0;
    }
    if (s[0] == '+') {
      flag = true;
      continue;
    }
    if (!flag) {
      sum1 = sum1 * 10 + mp[s];
    } else {
      sum2 = sum2 * 10 + mp[s];
    }
  }
}