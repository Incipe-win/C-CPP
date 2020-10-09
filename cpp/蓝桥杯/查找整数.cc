#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
  int n;
  int target;
  int nums[1003];

public:
  Solution(int n_, int target_, int nums_[1003]) {
    n = n_;
    target = target_;
    for (int i = 0; i < n; ++i) {
      nums[i] = nums_[i];
    }
  }
  void find() {
    bool flag = false;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == target) {
        cout << i + 1 << endl;
        flag = true;
        break;
      }
    }
    if (!flag) {
      cout << "-1" << endl;
    }
  }
};

int main() {
  int n;
  cin >> n;
  int nums[n];
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  int target;
  cin >> target;

  Solution so(n, target, nums);
  so.find();
  return 0;
}