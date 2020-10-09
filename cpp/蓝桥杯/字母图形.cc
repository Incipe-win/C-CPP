#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
  int n;
  int m;

public:
  Solution(int n_, int m_) {
    n = n_;
    m = m_;
  }

  void solve() {
    string str = "";
    for (int i = 0; i < m; ++i) {
      str += ('A' + i);
    }
    cout << str << endl;
    for (int i = 1; i < n; ++i) {
      trans(str, i);
    }
  }

  void trans(string &str, int i) {
    // str.pop_back();//蓝桥杯不可用！
    str.erase(str.end() - 1);
    str.insert(0, 1, (i + 'A'));
    cout << str << endl;
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  Solution so(n, m);
  so.solve();
  return 0;
}