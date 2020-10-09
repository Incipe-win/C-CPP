#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
  int year;

public:
  Solution(int year_) : year(year_) {}
  bool isLeapyear() {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  int year;
  cin >> year;
  Solution so(year);
  if (so.isLeapyear()) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}