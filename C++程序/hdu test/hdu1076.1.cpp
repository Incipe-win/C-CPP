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
  int next_leap_year(int _Year);

private:
  int m_iYear;
};

int IsLeapyear::next_leap_year(int _Year) {
  _Year += 4;
  while (!(IsLeapyear::ISLeapyear(_Year)))
    _Year += 4;
  return _Year;
}

int main() {
  int n;
  IsLeapyear Leapyear;
  cin >> n;
  while (n--) {
    int year, d;
    cin >> year >> d;
    while (!Leapyear.ISLeapyear(year))
      year += 4 - (year % 4);
    for (int i = 1; i < d; i++)
      year = Leapyear.next_leap_year(year);
    cout << year << endl;
  }
  return 0;
}
