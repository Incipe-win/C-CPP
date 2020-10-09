#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::string temp;
  std::map<std::string, int> mp;
  std::map<int, std::string> pm;
  pm[0] = "zero";
  pm[1] = "one";
  pm[2] = "two";
  pm[3] = "three";
  pm[4] = "four";
  pm[5] = "five";
  pm[6] = "six";
  pm[7] = "seven";
  pm[8] = "eight";
  pm[9] = "nine";
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
      int sum = sum1 + sum2, i = 0;
      if (sum < 10)
        cout << pm[sum] << endl;
      else {
        while (sum != 0) {
          temp[i++] = sum % 10;
          sum /= 10;
        }
        for (int j = i - 1; j >= 0; --j)
          cout << pm[temp[j]] << " ";
        cout << endl;
      }
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