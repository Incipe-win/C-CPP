#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  void print() {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          for (int l = 0; l < 2; ++l) {
            for (int n = 0; n < 2; ++n) {
              cout << i << j << k << l << n << endl;
            }
          }
        }
      }
    }
  }
};

int main() {
  Solution so;
  so.print();
  return 0;
}