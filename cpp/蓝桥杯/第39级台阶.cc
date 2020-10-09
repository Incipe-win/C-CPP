/*
题目描述：

小明刚刚看完电影《第39级台阶》，离开电影院的时候，他数了数礼堂前的台阶数，恰好是39级!

站在台阶前，他突然又想着一个问题：
   
如果我每一步只能迈上1个或2个台阶。先迈左脚，然后左右交替，最后一步是迈右脚，也就是说一共要走偶数步。那么，上完39级台阶，有多少种不同的上法呢？

输出格式：

输出一个整数

*/

#include <algorithm>
#include <iostream>

using namespace std;

int ans = 0;

class Solution {
public:
  Solution() {}
  void solve(int n, int step) {
    if (n < 0)
      return;
    if (n == 0) {
      if (step % 2 == 0) {
        ans++;
      }
      return;
    }
    solve(n - 1, step + 1);
    solve(n - 2, step + 1);
  }
};

int main() {
  Solution so;
  so.solve(39, 0);
  cout << ans << endl;
  return 0;
}