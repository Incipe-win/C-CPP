#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void Perc_Down(vector<int> &nums, int p, int len) {
  //将N个元素的数组中以nums[p]为根的子堆调整为最大堆
  int Parent, Child;
  int x;
  x = nums[p];  //取出根节点存放的值
  for (Parent = p; (Parent * 2 + 1) < len; Parent = Child) {
    Child = Parent * 2 + 1;
    if ((Child != len - 1) && (nums[Child] < nums[Child + 1])) {
      Child++;  // Child指向左右子节点的较大者
    }
    if (x >= nums[Child])
      break;  //找到了合适的位置
    else      //下滤x
      nums[Parent] = nums[Child];
  }
  nums[Parent] = x;
}
void Heap_Sort(vector<int> &nums, int len) {
  //堆排序
  //建立最大堆
  for (int i = len / 2 - 1; i >= 0; --i) Perc_Down(nums, i, len);
  for (int i = len - 1; i > 0; --i) {
    //删除最大堆
    swap(nums[0], nums[i]);
    Perc_Down(nums, 0, i);
  }
}

int main() {
  vector<int> nums{8, 5, 6, 4, 2, 7, 3, 1, 9, 10};
  int len = nums.size();
  Heap_Sort(nums, len);
  vector<int>::iterator it;
  for (it = nums.begin(); it != nums.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}