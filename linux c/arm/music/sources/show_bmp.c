#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

extern int fd;
extern unsigned int* plcd;

/**
 *  绘制图片
 * */
void lcd_drawpoint(int w, int h, unsigned int color) {
  //(w,h)显示了color色
  *(plcd + w + h * 800) = color;
}

/**
 *  读取bmp图片数据
 * */
void show_bmp(int x0, int y0, int w, int h, const char* bmp_file) {
  int bmp = 0;
  bmp = open(bmp_file, O_RDONLY);
  if (-1 == bmp) {
    perror("open bmp error");
    exit(-1);
  }

  //读取BMP和DIB数据
  int ret = 0;
  // BMP头和DIB数据
  unsigned char ch[64] = {0};
  ret = read(bmp, ch, 54);
  if (-1 == ret) {
    perror("read bmp error");
    exit(-1);
  } else if (0 == ret) {
    printf("no read data or file end\n");
    exit(-1);
  }

  // 3.处理数据
  int file_size = 0;
  int width = 0, hight = 0, pix_bit = 0;
  unsigned int color = 0;
  // rgba位图
  unsigned char a, r, g, b;
  //存储图像的位图数据(各个像素点颜色值分量)
  unsigned char pix[800 * 480 * 4] = {0};
  file_size = ch[2] | ch[3] << 8 | ch[4] << 16 | ch[5] << 24;
  width = ch[0x12] | ch[0x13] << 8 | ch[0x14] << 16 | ch[0x15] << 24;
  hight = ch[0x16] | ch[0x17] << 8 | ch[0x18] << 16 | ch[0x19] << 24;
  pix_bit = ch[0x1c] | ch[0x1d] << 8;

  //读取位图数据
  read(bmp, pix, w * h * pix_bit / 8);

  int i = 0;
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      b = pix[i++];
      g = pix[i++];
      r = pix[i++];
      a = (pix_bit == 32) ? pix[i++] : 0;
      color = a << 24 | r << 16 | g << 8 | b;
      lcd_drawpoint(x0 + x, y0 + ((h - 1) - y), color);
    }
  }
  close(bmp);
}
