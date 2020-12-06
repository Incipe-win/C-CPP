#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int m;
  cin >> m;
  vector<int> is_prime(m);
  for (int i = 0; i < m; ++i) {
    is_prime[i] = true;
  }
  is_prime[0] = is_prime[1] = false;
  int cnt = 0;
  for (int i = 0; i <= m; ++i) {
    if (is_prime[i]) {
      for (int j = i * 2; j <= m; j += i) {
        is_prime[j] = false;
      }
    }
    if (is_prime[i]) {
      ++cnt;
    }
  }
  cout << cnt << endl;
  return 0;
}
