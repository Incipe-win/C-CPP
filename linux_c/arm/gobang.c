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
void drawpoint(int x, int y, int k);
void lcd_close();
void lcd_open();

int lcd;
int *plcd;
int ts;
int f[15][15];

int main() {
  const char *bmp = "2.bmp";
  lcd_open();
  showbmp(bmp);
  int x = 0, y = 0;
  int k = 1;
  while (1) {
    get_xy(&x, &y);
    drawpoint(x, y, k);
    for (int m = 0; m < 15; m++) {
      for (int n = 0; n < 15; n++) {
        if (f[m][n] == f[m + 1][n + 1] == f[m + 2][n + 2] == f[m + 3][n + 3] ==
                f[m + 4][n + 4] == 1 ||
            f[m][n] == f[m + 1][n + 1] == f[m + 2][n + 2] == f[m + 3][n + 3] ==
                f[m + 4][n + 4] == 2 ||
            f[m][n] == f[m + 1][n + 1] == f[m + 2][n + 2] == f[m - 1][n - 1] ==
                f[m - 2][n - 2] == 1 ||
            f[m][n] == f[m + 1][n + 1] == f[m + 2][m + 2] == f[m - 1][n - 1] ==
                f[m - 2][n - 2] == 2) {
          if (k % 2 == 1) {
            printf("heiqisheng");
            break;
          }
          if (k % 2 == 0) {
            printf("baiqisheng");
            break;
          }
        }
      }
    }
    k++;
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

void drawpoint(int x, int y, int k) {
  int m = 0, n = 0;
  if (k % 2 == 1 && f[m][n] == 0) {
    for (int b = 0; b < 480; ++b) {
      for (int a = 0; a < 800; ++a) {
        if ((a - x) * (a - x) + (b - y) * (b - y) <= 10 * 10) {
          *(plcd + b * 800 + a) = 0x000000;
          n = (x - 220) / 26;
          m = (y - 60) / 26;
          f[m][n] = 1;
          printf("m: %d n: %d", m, n);
          printf("k: %d", f[m][n]);
        }
      }
    }
  }
  if (k % 2 == 0 && f[m][n] == 0) {
    for (int b = 0; b < 480; ++b) {
      for (int a = 0; a < 800; ++a) {
        if ((a - x) * (a - x) + (b - y) * (b - y) <= 10 * 10) {
          *(plcd + b * 800 + a) = 0x00FFFFFF;
          n = (x - 220) / 26;
          m = (y - 60) / 60;
          f[m][n] = 2;
        }
      }
    }
  }
}

void get_xy(int *x, int *y) {
  int c[15][2] = {207, 233, 233, 259, 259, 285, 285, 311, 311, 337,
                  337, 363, 363, 389, 389, 415, 415, 441, 441, 467,
                  467, 493, 493, 519, 519, 545, 545, 571, 571, 597};
  int d[15][2] = {34,  60,  60,  86,  86,  112, 112, 138, 138, 164,
                  164, 190, 190, 216, 216, 242, 242, 268, 268, 294,
                  294, 320, 320, 346, 346, 372, 372, 398, 398, 424};
  struct input_event touch;
  while (1) {
    read(ts, &touch, sizeof(touch));
    if (touch.type == EV_ABS && touch.code == ABS_X) *x = touch.value * 0.8;
    for (int j = 0; j < 15; j++) {
      if (*x > c[j][0] && *x <= c[j][1]) *x = c[j][0] + 13;
    }

    if (touch.type == EV_ABS && touch.code == ABS_Y) *y = touch.value * 0.8;
    for (int k = 0; k < 15; k++) {
      if (*y > d[k][0] && *y <= d[k][1]) *y = d[k][0] + 13;
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
