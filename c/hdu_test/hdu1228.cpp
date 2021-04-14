#include <cstdio>
#include <cstring>
#include <iostream>

char nums[10][10] = {"zero", "one", "two",   "three", "four",
                     "five", "six", "seven", "eight", "nine"};

int change(char str[]) {
  for (int i = 0; i < 10; i++) {
    if (strcmp(nums[i], str) == 0)
      return i;
  }
  return 0;
}

int main() {
  char str[10];
  while (1) {
    int a = 0, b = 0;
    while (scanf("%s", str) && strcmp(str, "+")) {
      a = a * 10 + change(str); //要学会这招
    }
    while (scanf("%s", str) && strcmp(str, "=")) {
      b = b * 10 + change(str);
    }
    if (a == 0 && b == 0) //两个zero时结束程序
      break;
    else {
      std::cout << a + b << std::endl;
    }
  }
  return 0;
}