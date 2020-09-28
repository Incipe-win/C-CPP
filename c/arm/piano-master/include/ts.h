#ifndef __TS_H_
#define __TS_H_

#include <dirent.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <linux/input.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct coordinate {
  int x;
  int y;
};
void Init_Ts(void);
void UnInit_Ts(void);
void wait4touch(struct coordinate *coor, bool *released);

#endif
