#include <stdio.h>

#include "exercise.h"

void print(unsigned char *buf) {
  printf("%x, %x, %x, %x\n", buf[2], buf[3], buf[4], buf[5]);
  printf("%x, %x, %x, %x\n", buf[0x12], buf[0x13], buf[0x14], buf[0x15]);
  printf("%x, %x, %x, %x\n", buf[0x16], buf[0x17], buf[0x18], buf[0x19]);
  printf("%x, %x\n", buf[0x1c], buf[0x1d]);
  ssize_t file_size = 0, file_width = 0, file_height = 0, colors_depth = 0;
  file_size = buf[2] | buf[3] << 8 | buf[4] << 16 | buf[5] << 24;
  file_width = buf[0x12] | buf[0x13] << 8 | buf[0x14] << 16 | buf[0x15] << 24;
  file_height = buf[0x16] | buf[0x17] << 8 | buf[0x18] << 16 | buf[0x19] << 24;
  colors_depth = buf[0x1c] | buf[0x1d] << 8;
  printf(
      "file_size: %lu, file_width: %lu, file_height: %lu, colors_depth: %lu\n",
      file_size, file_width, file_height, colors_depth);
}
