#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

extern void lcd_init();
extern void lcd_uninit();
extern void get_touch(int *, int *);
extern void close_ts();
extern void show_bmp(int, int, int, int, const char *);
extern void play_music();
extern void stop_music();
extern void next_music();
extern void pre_music();

bool isFirst = true;
bool isPlay = false;
bool flag = false;
int vol = 0;

/**
 *  处理信号函数
 * */
void my_handler(int sig) {
  // 最好不加
  printf("End of program, end of code: %d\n", sig);
  flag = true;
}

int main(int argc, char *argv[]) {
  // argv[0] 文件名 argv[1] 音量大小
  if (argc != 2) {
    vol = 0;
  } else {
    switch (atoi(argv[1])) {
      case 0:
        vol = -175;
        break;
      case 1:
        vol = -15;
        break;
      case 2:
        vol = 0;
        break;
      case 3:
        vol = 10;
        break;
    }
  }
  signal(SIGINT, my_handler);
  const char *background_bmp = "./bmp/background.bmp";
  const char *next_bmp = "./bmp/next.bmp";
  const char *pre_bmp = "./bmp/pre.bmp";
  const char *pause_bmp = "./bmp/pause.bmp";
  const char *play_bmp = "./bmp/play.bmp";
  lcd_init();
  show_bmp(0, 0, 800, 480, background_bmp);
  show_bmp(44, 340, 100, 100, pre_bmp);
  show_bmp(375, 340, 100, 100, pause_bmp);
  show_bmp(639, 340, 100, 100, next_bmp);
  // 触屏得到的坐标
  int x = 0, y = 0;
  while (1) {
    if (flag) {
      // 不让程序自动处理ctrl + z/c
      system("killall -9 madplay");
      show_bmp(375, 340, 100, 100, pause_bmp);
      flag = false;
      break;
    }
    get_touch(&x, &y);
    if (!flag) {
      if (375 < x && x < 475 && 340 < y && y < 440) {
        // 如果正在播放音乐，就停止播放音乐
        // 如果音乐没有播放，就开始播放音乐
        if (isPlay) {
          stop_music();
          show_bmp(375, 340, 100, 100, pause_bmp);
          isPlay = false;
        } else {
          play_music();
          show_bmp(375, 340, 100, 100, play_bmp);
          isPlay = true;
          isFirst = false;
        }
      }
      // 上一首音乐
      if (45 < x && x < 145 && 340 < y && y < 440) {
        pre_music();
        show_bmp(375, 340, 100, 100, play_bmp);
        isFirst = false;
        isPlay = true;
      }
      // 下一首音乐
      if (639 < x && x < 739 && 340 < y && y < 440) {
        next_music();
        show_bmp(375, 340, 100, 100, play_bmp);
        isFirst = false;
        isPlay = true;
      }
    }
  }
  close_ts();
  lcd_uninit();
  return 0;
}
