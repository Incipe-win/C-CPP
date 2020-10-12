#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int *nums = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  sort(nums, nums + n);
  for (int i = 0; i < n; ++i) {
    if (i == n - 1) {
      cout << nums[i] << endl;
    } else {
      cout << nums[i] << " ";
    }
  }
  return 0;
}