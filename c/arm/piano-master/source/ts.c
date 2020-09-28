#include <string.h>

#include "ts.h"

int ts;

void Init_Ts(void) {
  ts = open("/dev/input/event0", O_RDONLY);
  if (-1 == ts) {
    perror("open ts fail");
    return;
  }
}
void UnInit_Ts(void) { close(ts); }

void wait4touch(struct coordinate *coor, bool *released) {
  struct input_event buf;

  bool x_ready = false;
  bool y_ready = false;

  while (1) {
    bzero(&buf, sizeof(buf));
    read(ts, &buf, sizeof(buf));
    if (buf.type == EV_KEY && buf.code == BTN_TOUCH && buf.value == 0) {
      *released = true;
      break;
    } else
        // {
        // 	*released = false;
        // }

        if (buf.type == EV_ABS && buf.code == ABS_X) {
      coor->x = buf.value;
      x_ready = true;
    }

    if (buf.type == EV_ABS && buf.code == ABS_Y) {
      coor->y = buf.value;
      y_ready = true;
    }

    if (x_ready && y_ready) break;
  }
  // coor->x =0;
  // coor->y =0;
}
