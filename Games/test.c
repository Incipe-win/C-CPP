/*************************************************************************
	> File Name: test.c
	> Author: incipe
	> Mail: chaoh7461@gmail.com
	> Created Time: Fri Jan 17 12:43:26 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

int a[4][4];

int empty;
int old_x, old_y;

void draw();
void play();
void init();
void draw_one(int y, int x);
void cnt_value(int *new_y, int *new_x);
int game_over();
int cnt_one(int y, int x);

void init() {
	int x, y;

	initscr();
	cbreak();
	noecho();
	curs_set(0);

	empty = 15;
	srand(time(0));
	x = rand() % 4;
	y = rand() % 4;
	a[y][x] = 2;
	draw();
}

void draw() {
	int n, m, x, y;
	char c[4] = {'0', '0', '0', '0'};
	clear();

	for (n = 0; n < 9; n += 2) {
		for (m = 0; m < 21; m++) {
			move(n, m);
			addch('-');
			refresh();
		}
	}
	for(m = 0; m < 22; m += 5) {
		for(n = 1; n < 8; n++) {
			move(n, m);
			addch('|');
			refresh();
		}
	}
	for(y = 0; y < 4; y++) {
		for(x = 0; x < 4; x++) {
			draw_one(y, x);
		}
	}
}

void draw_one(int y, int x) {
	int i, m, k, j;
	char c[5] = {0x00};
	i = a[y][x];
	m = 0;
	while(i > 0) {
		j = i % 10;
		c[m++] = j + '0';
		i = i / 10;
	}
	m = 0;
	k = (x + 1) * 5 - 1;
	while(c[m] != 0x00) {
		move(2 * y + 1, k);
		addch(c[m++]);
		k--;
	}
}

void play() {
	int x, y, i, new_x, new_y, temp;
	int old_empty, move;
	char ch;
	while(1) {
		move = 0;
		old_empty = empty;
		ch = getch();
		switch(ch) {
			case 97:
			case 104:
			case 68:
				for(y = 0; y < 4; y++) {
					for(x = 0; x < 4; ) {
						if(a[y][x] == 0) {
							x++;
							continue;
						} else {
							for(i = x + 1; i < 4; i++) {
								if(a[y][x] == 0) {
									continue;
								} else {
									if(a[y][x] == a[y])
								}
							}
						}
					}
				}
		}
	}
}


int main() {
	init();
	play();
	endwin();

	return 0;
}
