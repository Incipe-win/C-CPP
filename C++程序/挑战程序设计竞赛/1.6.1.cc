#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  bool flag = true;
  int n, maxn = 0, len;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        len = a[i] + a[j] + a[k];
        if ((a[i] + a[j] > a[k]) && (a[i] + a[k] > a[j]) &&
            (a[j] + a[k] > a[i])) {
          maxn = len;
          flag = false;
        }
      }
    }
  }
  if (flag) {
    cout << 0 << endl;
  } else {
    cout << maxn << endl;
  }
  return 0;
}