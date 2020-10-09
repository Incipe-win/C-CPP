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

void my_handler(int sig) {
  // 最好不加
  printf("End of program, end of code: %d\n", sig);
  flag = true;
}

int main() {
  signal(SIGINT, my_handler);
  const char *music = "./bmp/music.bmp";
  lcd_init();
  show_bmp(0, 0, 800, 480, music);
  int x = 0, y = 0;
  while (1) {
    if (flag) {
      system("killall -9 madplay");
      flag = false;
      break;
    }
    get_touch(&x, &y);
    if (!flag) {
      if (455 < x && x < 565 && 250 < y && y < 335) {
        play_music();
        isFirst = false;
        isPlay = true;
      }
      if (565 < x && x < 640 && 250 < y && y < 335) {
        stop_music();
        isPlay = false;
      }
      if (267 < x && x < 359 && 250 < y && y < 335) {
        pre_music();
        isFirst = false;
        isPlay = true;
      }
      if (645 < x && x < 733 && 250 < y && y < 335) {
        next_music();
        isFirst = false;
        isPlay = true;
      }
    }
  }
  close_ts();
  lcd_uninit();
  return 0;
}
