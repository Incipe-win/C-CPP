#include <stdio.h>
#include <stdlib.h>

int main() {
  //  printf("PWDpath is [%s]\n", getenv("PWD"));
  unsetenv("PWD");
  return 0;
}
