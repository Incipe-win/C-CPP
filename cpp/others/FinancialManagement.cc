#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void solved() {
    scan();
    double sum = 0.0;
    for (int i = 0; i < 12; ++i) {
      sum += vec[i];
    }
    print(sum);
  }
  void scan() {
    double temp;
    for (int i = 0; i < 12; ++i) {
      cin >> temp;
      vec.emplace_back(temp);
    }
  }
  void print(double sum) { printf("$%.2f\n", sum / 12.0); }

 private:
  vector<double> vec;
};

int main() {
  Solution s;
  s.solved();
  return 0;
}
