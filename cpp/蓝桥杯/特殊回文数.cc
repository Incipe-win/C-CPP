#include <algorithm>
#include <iostream>

using namespace std;

int is_palindromic_number(int number) {
  int tmp = 0, temp = number, value = 0;
  while (number) {
    tmp = tmp * 10 + (number % 10);
    value += number % 10;
    number /= 10;
  }
  if (tmp == temp) {
    return value;
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  for (int i = 10000; i < 1000000; ++i) {
    if (is_palindromic_number(i) == n) {
      cout << i << endl;
    }
  }
  return 0;
}