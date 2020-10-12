/*
大数学家高斯有个好习惯：无论如何都要记日记。

他的日记有个与众不同的地方，他从不注明年月日，而是用一个整数代替，比如：4210

后来人们知道，那个整数就是日期，它表示那一天是高斯出生后的第几天。这或许也是个好习惯，

它时时刻刻提醒着主人：日子又过去一天，还有多少时光可以用于浪费呢？

高斯出生于：1777年4月30日。

在高斯发现的一个重要定理的日记上标注着：5343，因此可算出那天是：1791年12月15日。

高斯获得博士学位的那天日记上标着：8113

请你算出高斯获得博士学位的年月日。

*/

#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  Solution() {}
  void solve() {
    int y = 1777, m = 4, d = 30;
    for (int i = 0; i < 8112; ++i) {
      d++;
      if (m == 12 && d == 32) {
        y++;
        m = 1;
        d = 1;
        continue;
      }
      if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10) &&
          d == 32) {
        m++;
        d = 1;
        continue;
      }
      if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 31) {
        m++;
        d = 1;
        continue;
      }
      if (m == 2 && isLeapyear(y) && d == 30) {
        d = 1;
        m++;
        continue;
      }
      if (m == 2 && !isLeapyear(y) && d == 29) {
        d = 1;
        m++;
        continue;
      }
    }
    cout << y << " " << m << " " << d << endl;
  }
  bool isLeapyear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  }
};

int main() {
  Solution so;
  so.solve();
  return 0;
}