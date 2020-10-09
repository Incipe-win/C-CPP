#include <bits/stdc++.h>
using namespace std;

class IsLeapyear {
public:
  int ISLeapyear(int _year) {
    m_iYear = _year;
    if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0) {
      return 1;
    }
    return 0;
  }

private:
  int m_iYear;
};

int main() {
  int n;
  IsLeapyear Leapyear;
  cin >> n;
  while (n--) {
    int year, d;
    cin >> year >> d;
    if (Leapyear.ISLeapyear(year)) {
      d--;
    }
    while (d) {
      year++;
      if (Leapyear.ISLeapyear(year)) {
        d--;
      }
    }
    cout << year << endl;
  }
  return 0;
}