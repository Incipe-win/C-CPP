#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class PascalTriangle {
public:
  PascalTriangle(int n_) : n(n_) { print(); }
  void print() {
    int tri[n][n];
    tri[0][0] = 1;
    tri[1][0] = 1;
    tri[1][1] = 1;
    cout << tri[0][0] << endl;
    cout << tri[1][0] << " " << tri[1][1] << endl;
    for (int i = 2; i < n; ++i) {
      tri[i][0] = 1;
      cout << tri[i][0] << " ";
      for (int j = 1; j <= i - 1; ++j) {
        tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
        cout << tri[i][j] << " ";
      }
      tri[i][i] = 1;
      cout << tri[i][i] << endl;
    }
  }

private:
  int n;
};

int main() {
  int n;
  cin >> n;
  PascalTriangle pas(n);
  return 0;
}