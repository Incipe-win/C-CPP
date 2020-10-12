#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Select_Sort(vector<int> nums, int len);

int main() {
  vector<int> nums{8, 5, 6, 4, 2, 7, 3, 1, 9, 10};
  int len = nums.size();
  Select_Sort(nums, len);
  return 0;
}

void Select_Sort(vector<int> nums, int len) {
  int min, m;

  for (int i = 0; i < len - 1; ++i) {
    min = i;
    for (int j = i + 1; j < len; ++j) {
      if (nums[min] > nums[j]) {
        min = j;
      }
    }
    if (min != i) {
      swap(nums[min], nums[i]);
      for (m = 0; m < len; ++m) {
        if (m > 0) {
          cout << " ";
        }
        cout << nums[m];
      }
      cout << endl;
    }
  }
}