#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void Shell_Sort(vector<int> &nums, int len) {
  int tmp, k;
  for (int i = len / 2; i > 0; i /= 2) {
    //希尔排序增量
    //插入排序
    for (int j = i; j < len; ++j) {
      tmp = nums[j];
      for (k = j; k >= i && nums[k - i] > tmp; k -= i) {
        nums[k] = nums[k - i];
      }
      nums[k] = tmp;
    }
  }
}
//增量选取

/*
// Sedgewick排序
void Shell_Sort(vector<int> &nums, int len) {
  int Si, D, P, i, tmp;
  //部分增量
  int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
  for (Si = 0; Sedgewick[Si] >= len; ++Si)
    ;
    //初始的增量Sedgewick[Si]不能超过待排序列长度
  for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si]) {
    //插入排序
    for (P = D; P < len; ++P) {
      tmp = nums[P];
      for (i = P; i >= D && nums[i - D] > tmp; i -= D) nums[i] = nums[i - D];
      nums[i] = tmp;
    }
  }
}
*/

int main() {
  vector<int> nums{8, 5, 6, 4, 2, 7, 3, 1, 9, 10};
  int len = nums.size();
  Shell_Sort(nums, len);
  for (int i = 0; i < len; ++i) {
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}
