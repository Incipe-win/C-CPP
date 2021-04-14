#ifndef __LCD_H__
#define __LCD_H__

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define LCD_WIDTH 800
#define LCD_HEIGHT 480
#define FB_SIZE (LCD_WIDTH * LCD_HEIGHT * 4)

unsigned long file_size_get(const char *pfile_path);
int lcd_open(void);
void lcd_close(void);
void lcd_draw_point(unsigned int x, unsigned int y, unsigned int color);
int lcd_draw_jpg(unsigned int x, unsigned int y, const char *pjpg_path,
                 char *pjpg_buf, unsigned int jpg_buf_size,
                 unsigned int jpg_half);
#endif  // __LCD_H_
