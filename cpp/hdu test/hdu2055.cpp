#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    char ch;
    getchar();
    int num, j = 1, k = 1;
    scanf("%c %d", &ch, &num);
    if (ch >= 'a' && ch <= 'z') {
      for (char i = 'a'; i <= 'z'; i++) {
        if (ch == i) {
          j = -j;
          break;
        }
        j++;
      }
      printf("%d\n", j + num);
    } else {
      for (char i = 'A'; i <= 'Z'; i++) {
        if (ch == i) {
          k = k;
          break;
        }
        k++;
      }
      printf("%d\n", k + num);
    }
  }
  return 0;
}
