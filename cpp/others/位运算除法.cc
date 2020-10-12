#include <algorithm>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

class Solution {
 public:
  Solution(int dividend_, int divisor_);
  ~Solution();
  int divide();

 private:
  int dividend;
  int divisor;
};

Solution::Solution(int dividend_, int divisor_)
    : dividend{dividend_}, divisor{divisor_} {
  cout << "Welecome Bit division !" << endl;
}

Solution::~Solution() { cout << "Have a good time !" << endl; }

int Solution::divide() {
  //位运算实现除法！
  if (dividend == 0) return 0;
  if (dividend == INT_MIN && divisor == -1) {
    return INT_MAX;
  }
  bool flag;
  flag = (dividend ^ divisor) < 0;  //判断dividend和divisor的符号是否相同
  /*负数的最高位为符号位，是1，正数最高位为0，1 ^ 0 =
   * 1；所以两个符号不同的数字异或后得到的结果肯定是负数！*/
  long t = abs(static_cast<long>(dividend));
  long d = abs(
      static_cast<long>(divisor));  //把负数转换为正数计算，负数计算不太友好。
  //位运算实现除法！
  long long result = 0;
  for (int i = 31; i >= 0; --i) {
    //比较x是否大于y的(1<<i)次方，避免将x与(y<<i)比较，因为不确定y的(1<<i)次方是否溢出
    if ((t >> i) >= d) {
      result += 1 << i;
      t -= d << i;
    }
    /* 依次减掉（如果x够减的）y^(2^31),y^(2^30),...y^8,y^4,y^2,y^1。
       减掉相应数量的y就在结果加上相应的数量。
    */
  }
  return flag ? -result : result;
}

int main() {
  Solution s(9, -3);
  cout << s.divide() << endl;
  return 0;
}