#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  string num;
  long long result = 0;
  cin >> num;
  int len = num.size();
  for (int i = 0; i < len; ++i) {
    if (num[i] == 'A') {
      //权为len - 1 - i
      result += 10 * pow(16, (len - 1 - i));
    } else if (num[i] == 'B') {
      result += 11 * pow(16, (len - 1 - i));
    } else if (num[i] == 'C') {
      result += 12 * pow(16, (len - 1 - i));
    } else if (num[i] == 'D') {
      result += 13 * pow(16, (len - 1 - i));
    } else if (num[i] == 'E') {
      result += 14 * pow(16, (len - 1 - i));
    } else if (num[i] == 'F') {
      result += 15 * pow(16, (len - 1 - i));
    } else {
      result += (num[i] - '0') * pow(16, (len - 1 - i));
    }
  }
  cout << result << endl;
  return 0;
}