#include <fcntl.h>
#include <linux/input.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char music[7][6] = {"1.mp3", "2.mp3", "3.mp3", "4.mp3",
                    "5.mp3", "6.mp3", "7.mp3"};

int order = 0;

extern bool isFirst;
extern bool isPlay;
extern int vol;

/**
 *  播放音乐
 *  如果是第一次播放就开始播放
 *  如果不是，就继续播放
 * */
void play_music() {
  if (isFirst) {
    char command[100] = {0};
    sprintf(command, "madplay %s -a %d &", music[order], vol);
    printf("%s\n", command);
    system(command);
  } else {
    system("killall -CONT madplay &");
  }
}

/**
 *  暂停音乐
 * */
void stop_music() { system("killall -STOP madplay &"); }

/**
 *  下一首
 * */
void next_music() {
  system("killall -9 madplay");

  if (order == 6) {
    order = -1;
  }
  char command[100] = {0};
  sprintf(command, "madplay %s -a %d &", music[++order], vol);
  printf("%s\n", command);
  system(command);
}

/**
 *  上一首
 * */
void pre_music() {
  system("killall -9 madplay");
  if (order == 0) {
    order = 7;
  }
  char command[100] = {0};
  sprintf(command, "madplay %s -a %d &", music[--order], vol);
  printf("%s\n", command);
  system(command);
}
