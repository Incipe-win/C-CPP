#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
  int n;
  int nums[10003];

public:
  Solution(int n_, int nums_[10003]) {
    n = n_;
    for (int i = 0; i < n; ++i) {
      nums[i] = nums_[i];
    }
  }

  void find() {
    int min = 100000, max = -100000, sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      if (nums[i] < min) {
        min = nums[i];
      }
      if (nums[i] > max) {
        max = nums[i];
      }
    }
    cout << max << endl;
    cout << min << endl;
    cout << sum << endl;
  }
};

int main() {
  int n;
  cin >> n;
  int nums[n];
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  Solution so(n, nums);
  so.find();
  return 0;
}