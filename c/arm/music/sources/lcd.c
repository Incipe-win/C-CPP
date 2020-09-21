#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int fd = 0;
unsigned int *plcd = NULL;

void lcd_init() {
  fd = open("/dev/fb0", O_RDWR);
  if (fd == -1) {
    perror("file error: ");
    exit(-1);
  }
  plcd = (unsigned int *)mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE,
                              MAP_SHARED, fd, 0);
  if (plcd == MAP_FAILED) {
    perror("mmap error: ");
    exit(-1);
  }
}

void lcd_uninit() {
  munmap(plcd, 800 * 480 * 4);
  close(fd);
}
