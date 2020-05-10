#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void solved(vector<string> &vec) {
    int size = vec.size();
    for (int i = 0; i < size; ++i) {
      if (vec[i].size() > 10) {
        // cout << vec[i][0] << " " << vec[i][vec[i].size() - 1] << endl;
        string str = vec[i][0] + to_string(vec[i].size() - 2) +
                     vec[i][vec[i].size() - 1];
        // cout << str << endl;
        vec[i] = str;
        // vec[i] = vec[i][0] + size - 2 + vec[i][size - 1];
      }
    }
    print(vec);
  }

  void print(const vector<string> &vec) {
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i) {
      cout << vec[i] << endl;
    }
  }
};

int main() {
  Solution s;
  vector<string> vec;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    getchar();
    string str;
    cin >> str;
    vec.emplace_back(str);
  }
  s.solved(vec);
  return 0;
}