#include <algorithm>
#include <iostream>

using namespace std;

bool is_palindromic_number(int number) {
  int tmp = 0, temp = number; //, value = 0;
  while (number) {
    tmp = tmp * 10 + (number % 10);
    // value += number % 10;
    number /= 10;
  }
  if (tmp == temp) {
    return true; // value;
  }
  return false;
}

int main() {
  for (int i = 1000; i < 10000; ++i) {
    if (is_palindromic_number(i)) {
      cout << i << endl;
    }
  }
  return 0;
}