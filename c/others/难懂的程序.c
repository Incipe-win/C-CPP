#include <stdio.h>
struct tt {
  int x;
  struct tt *next;
} s[2] = {1, 0, 5, 0};

int main() {
  struct tt *p = s;
  p->next = s;
  printf("%d", ++p->x);
}
