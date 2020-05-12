#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int num = 3;
  char filename[128] = {0};
  while (1) {
    sprintf(filename, "temp_%4d", num++);
    int fd = open(filename, O_CREATE | O_RDONLY, 0666);
    if (fd < 0) {
      perror("open err ");
      // close(fd);
      break;
    }
    // close(fd);
  }
  return 0;
}
