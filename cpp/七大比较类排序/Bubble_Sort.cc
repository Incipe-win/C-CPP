#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

void Bubble_Sort(vector<int> &nums, int len) {
  for (int i = len - 1; i >= 0; --i) {
    bool flag = false;
    for (int j = 0; j < i; ++j) {
      if (nums[j] > nums[j + 1]) {
        swap(nums[j], nums[j + 1]);
        flag = true;
      }
    }
    if (!flag) {
      break;
    }
  }
}

int main() {
  vector<int> nums{8, 5, 6, 4, 2, 7, 3, 1, 9, 10};
  int len = nums.size();
  Bubble_Sort(nums, len);
  vector<int>::iterator it;
  for (it = nums.begin(); it != nums.end(); ++it) cout << *it << " ";
  cout << endl;
  return 0;
}