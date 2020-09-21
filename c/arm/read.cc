#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int a = 0;
  unsigned char ch[4] = {0x78, 0x56, 0x34, 0x12};
  a = ch[0];
  a = a >> 8;
  a = ch[1];
  a = a >> 16;
  a = ch[2];
  a = a >> 24;
  a = ch[3];
  printf("%d\n", a);
  return 0;
}
