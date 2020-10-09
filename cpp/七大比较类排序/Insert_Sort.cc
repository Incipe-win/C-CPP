#include <iostream>
#include <vector>
using namespace std;

void Insert_Sort(vector<int> &nums, int len);

int main() {
  vector<int> nums{8, 5, 6, 4, 2, 7, 3, 1, 9, 10};
  int len = nums.size();
  Insert_Sort(nums, len);
  for (int i = 0; i < len; ++i) {
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}

void Insert_Sort(vector<int> &nums, int len) {
  int tmp, j;
  for (int i = 1; i < len; ++i) {
    tmp = nums[i];
    for (j = i; j > 0 && nums[j - 1] > tmp; --j) {
      nums[j] = nums[j - 1];
    }
    nums[j] = tmp;
  }
}