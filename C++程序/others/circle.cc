#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> vec(21, 0);
vector<bool> flag(20, false);

class Solution {
 private:
  bool judge(int n) {
    if (n < 2) {
      return false;
    }
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }

  void recusive(int s) {
    if (s == n && judge(vec[1] + vec[n])) {
      for (int i = 1; i < n; ++i) {
        cout << vec[i] << " ";
      }
      cout << vec[n] << endl;
    } else {
      for (int i = 2; i <= n; ++i) {
        if (!flag[i] && judge(i + vec[s])) {
          flag[i] = true;
          vec[s + 1] = i;
          recusive(s + 1);
          flag[i] = false;
        }
      }
    }
  }

 public:
  void solve() {
    int t = 0;
    while (cin >> n) {
      vec[1] = 1;
      ++t;
      cout << "Case " << t << ":" << endl;
      recusive(1);
      cout << endl;
    }
  }
};

int main() {
  Solution s;
  s.solve();
  return 0;
}
