#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while (cin >> n) {
    int k = 0;
    for (int i = 1; i <= n; i++) {
      if (n % i == 0) {
        k++;
      }
    }
    if (k % 2 == 0) {
      cout << "0" << endl;
    } else {
      cout << "1" << endl;
    }
  }
  return 0;
}