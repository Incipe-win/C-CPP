#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("./a.out strfile dstfile\n");
    return -1;
  }
  // 5进程
  int n = 5;
  // 打开，要被复制的文件
  int fd1 = open(argv[1], O_RDONLY);
  if (fd1 < 0) {
    perror("open_src:");
    exit(1);
  }
  // 打开，要复制的文件
  int fd2 = open(argv[2], O_CREAT | O_RDWR | O_TRUNC, 0666);
  if (fd2 < 0) {
    perror("open_dst:");
    exit(2);
  }
  // 计算文件大小
  int flen = lseek(fd1, 0, SEEK_END);
  printf("flen = %d\n", flen);
  // 扩展文件大小
  ftruncate(fd2, flen);
  char *src = (char *)mmap(NULL, flen, PROT_READ, MAP_SHARED, fd1, 0);
  if (src == MAP_FAILED) {
    printf("mmap_src error:");
    exit(3);
  }
  close(fd1);
  char *dst =
      (char *)mmap(NULL, flen, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);
  if (dst == MAP_FAILED) {
    perror("mmap_dst error:");
    exit(4);
  }
  close(fd2);
  // 分成part部分，除不尽的留给最后一个进程
  int part = flen / n;
  int remain = flen % n;
  printf("part = %d, remain = %d\n", part, remain);

  int i;
  pid_t pid;
  for (i = 0; i < n; ++i) {
    // 创建n个进程
    printf("%dth process\n", i);
    if ((pid = fork()) == 0) {
      break;
    }
  }
  if (n == i) {
    // 父进程，需要释放子进程资源
    for (int j = 0; j < n; ++j) {
      wait(NULL);
    }
  } else if (i == (n - 1)) {
    printf("i = %d\n", i);
    // 最后一个子进程,要把除不尽的也拷贝了。
    memcpy(dst + i * part, src + i * part, part + remain);
  } else if (i == 0) {
    printf("i = %d\n", i);
    // 第一个子进程，从最初的位置开始拷贝
    memcpy(dst, src, part);
  } else {
    printf("i = %d\n", i);
    // 另外的子进程，拷贝
    memcpy(dst + i * part, src + i * part, part);
  }
  // 释放mmap
  munmap(src, flen);
  munmap(dst, flen);
  return 0;
}
