#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// lcd 文件描述符
int fd = 0;
// 共享映射区首地址
unsigned int *plcd = NULL;

/**
 *  打开lcd屏幕和共享映射区
 * */
void lcd_init() {
  fd = open("/dev/fb0", O_RDWR);
  if (fd == -1) {
    perror("lcd open error: ");
    exit(-1);
  }
  // 打开共享映射区
  plcd = (unsigned int *)mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE,
                              MAP_SHARED, fd, 0);
  if (plcd == MAP_FAILED) {
    perror("mmap error: ");
    exit(-1);
  }
}

/**
 *  关闭lcd屏幕和映射区
 * */
void lcd_uninit() {
  // 关闭共享映射区
  munmap(plcd, 800 * 480 * 4);
  // 关闭文件描述符
  close(fd);
}
