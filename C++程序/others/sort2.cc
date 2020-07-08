#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 private:
  void recusive(set<vector<int>> &s, vector<int> &array, vector<int> &vec,
                vector<bool> &flag) {
    if (vec.size() == 4) {
      s.insert(vec);
      return;
    }
    for (int i = 0; i < 4; ++i) {
      if (!flag[i]) {
        flag[i] = true;
        vec.emplace_back(array[i]);
        recusive(s, array, vec, flag);
        flag[i] = false;
        vec.pop_back();
      }
    }
  }

  void print(const set<vector<int>> &s, int flag) {
    set<vector<int>>::iterator it;
    int xa = 0;
    for (it = s.begin(); it != s.end(); ++it) {
      if ((*it)[0] == 0) {
        continue;
      }
      if ((*it)[0] != flag) {
        flag = (*it)[0];
        cout << endl;
        xa = 0;
      }
      if (xa) {
        cout << " ";
      }
      ++xa;
      for (auto x : *it) {
        cout << x;
      }
    }
    cout << endl;
  }

 public:
  void solve() {
    int x1, x2, x3, x4;
    int a = 0;
    while (cin >> x1 >> x2 >> x3 >> x4) {
      if (x1 == 0 && x2 == 0 && x3 == 0 && x4 == 0) {
        break;
      }
      if (a) {
        cout << endl;
      }
      ++a;
      vector<int> vec;
      vector<bool> flag(4, false);
      vector<int> array;
      set<vector<int>> s;
      array.emplace_back(x1);
      array.emplace_back(x2);
      array.emplace_back(x3);
      array.emplace_back(x4);
      int flag1 = x1 ? x1 : x2;
      recusive(s, array, vec, flag);
      print(s, flag1);
    }
  }
};

int main() {
  Solution s;
  s.solve();
  return 0;
}
