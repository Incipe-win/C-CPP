/*************************************************************************
        > File Name: wzq1.c
        > Author: csgec
        > Mail: 12345678@qq.com
        > Created Time: 2020年09月18日 星期五 19时50分59秒
 ************************************************************************/

#include <dirent.h>
#include <fcntl.h>
#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

void get_xy(int *x, int *y);
void showbmp(const char *namebmp);
void drawpoint(int x, int y);
void lcd_close();
void lcd_open();

int lcd;
int *plcd;
int ts;

int main() {
  const char *bmp = "2.bmp";
  lcd_open();
  showbmp(bmp);
  int x = 0, y = 0;
  while (1) {
    get_xy(&x, &y);
    drawpoint(x, y);
  }
  lcd_close();
  return 0;
}

void lcd_open() {
  lcd = open("/dev/fb0", O_RDWR);
  if (lcd == -1) {
    perror("file error: ");
    exit(-1);
  }
  plcd = (int *)mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED,
                     lcd, 0);
  if (plcd == MAP_FAILED) {
    perror("mmap error: ");
    exit(-1);
  }
  ts = open("/dev/input/event0", O_RDWR);
  if (ts == -1) {
    perror("ts error: ");
    exit(-1);
  }
}

void lcd_close() {
  munmap(plcd, 800 * 480 * 4);
  close(ts);
  close(lcd);
}

void drawpoint(int x, int y) {
  // r = 200 (x, y)
  for (int b = 0; b < 480; ++b) {
    for (int a = 0; a < 800; ++a) {
      if ((a - x) * (a - x) + (b - y) * (b - y) <= 10 * 10) {
        *(plcd + b * 800 + a) = 0x000000;
      }
    }
  }
}

void get_xy(int *x, int *y) {
  struct input_event touch;
  while (1) {
    read(ts, &touch, sizeof(touch));
    if (touch.type == EV_ABS && touch.code == ABS_X) {
      *x = touch.value;
    }
    if (touch.type == EV_ABS && touch.code == ABS_Y) {
      *y = touch.value;
    }
    if (touch.type == EV_KEY && touch.code == BTN_TOUCH && touch.value == 0) {
      printf("x:%d y:%d\n", *x, *y);
      break;
    }
  }
}

void showbmp(const char *namebmp) {
  int bmp = open(namebmp, O_RDONLY);
  if (bmp == -1) {
    perror("bmp error: ");
    exit(-1);
  }

  char buf[800 * 480 * 3];
  int new_buf[800 * 480] = {0};
  lseek(bmp, 54, SEEK_SET);
  read(bmp, buf, 800 * 480 * 3);
  int n;
  for (n = 0; n < 800 * 480; n++) {
    new_buf[n] = buf[3 * n] << 0 | buf[(3 * n) + 1] << 8 |
                 buf[(3 * n) + 2] << 16 | buf[(3 * n) + 3] << 24;
  }
  for (int b = 0; b < 480; b++) {
    for (int a = 0; a < 800; a++) {
      *(plcd + 800 * (479 - b) + a) = new_buf[800 * b + a];
    }
  }
}
