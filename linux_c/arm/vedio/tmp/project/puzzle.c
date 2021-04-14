#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "puzzle.h"

void puzzle() {
  int lt, rt, bmp;
  int lb, rb;
  BmpFileHead head;
  BmpInfoHead info;
  unsigned short bfType;
  unsigned char *lineBuf;
  int i, j, lineSize;

  if ((lt = open("./video_bmp/1.bmp", O_RDONLY)) < 0) {
    perror("open 1.bmp error: ");
    exit(-1);
  }
  if ((rt = open("./video_bmp/2.bmp", O_RDONLY)) < 0) {
    perror("open 2.bmp error: ");
    exit(-1);
  }
  if ((lb = open("./video_bmp/3.bmp", O_RDONLY)) < 0) {
    perror("open 3.bmp error: ");
    exit(-1);
  }
  if ((rb = open("./video_bmp/4.bmp", O_RDONLY)) < 0) {
    perror("open 4.bmp error: ");
    exit(-1);
  }
  if ((bmp = open("puzzle.bmp", O_CREAT | O_WRONLY, 0666)) < 0) {
    perror("open puzzle.bmp error: ");
    exit(-1);
  }

  read(lt, &bfType, sizeof(bfType));
  read(lt, &head, sizeof(head));
  read(lt, &info, sizeof(info));

  head.bfSize = head.bfSize * 4 - 54;
  info.biSizeImage = info.biSizeImage * 4;
  info.width = info.width * 2;
  info.height = info.height * 2;

  write(bmp, &bfType, sizeof(bfType));
  write(bmp, &head, sizeof(head));
  write(bmp, &info, sizeof(info));

  lineSize = (info.width / 2) * 3;
  lineBuf = (unsigned char *)malloc(lineSize);

  lseek(rt, 54, SEEK_SET);
  lseek(lb, 54, SEEK_SET);
  lseek(rb, 54, SEEK_SET);

  for (i = 0; i < 2; ++i) {
    for (j = 0; j < (int)info.height / 2; ++j) {
      if (i == 0) {
        read(lt, lineBuf, lineSize);
        write(bmp, lineBuf, lineSize);
        read(rt, lineBuf, lineSize);
        write(bmp, lineBuf, lineSize);
      }
      if (i == 1) {
        read(lb, lineBuf, lineSize);
        write(bmp, lineBuf, lineSize);
        read(rb, lineBuf, lineSize);
        write(bmp, lineBuf, lineSize);
      }
    }
  }
  close(lt);
  close(rt);
  close(bmp);
  close(rb);
  close(lb);
  free(lineBuf);
  printf("success!\n");
}
