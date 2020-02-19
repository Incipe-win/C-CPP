#include "public.h"
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord;
// Position the cursor

Snake::Snake(int _m, int _n, int _snakelen)
    : m_im(_m), m_in(_n), m_isnakelen(_snakelen) {}

Snake::~Snake() {}

void Snake::print_wall() {
  for (int i = 0; i < m_im; i++) {
    if (i == m_im - 1)
      cout << "-" << endl;
    else
      cout << "-";
  }
  for (int j = 0; j < m_in; j++) {
    cout << "|";
    for (int i = 0; i < m_im - 2; i++)
      cout << " ";
    cout << "|" << endl;
  }
  for (int i = 0; i < m_im; i++) {
    if (i == m_im - 1)
      cout << "-" << endl;
    else
      cout << "-";
  }
}

void Snake::locate(int x, int y) {
  coord.X = y;
  coord.Y = x;
  SetConsoleCursorPosition(hout, coord);
};

void Snake::hide() {
  CONSOLE_CURSOR_INFO cursor_info = {1, 0};
  SetConsoleCursorInfo(hout, &cursor_info);
}

double Snake::random(double start, double end) {
  return start + (end - start) * rand() / (RAND_MAX + 1.0);
}

void Snake::print_snake() {
  Snake::locate(snake[0].x, snake[0].y);
  cout << "#";
  for (int i = 1; i <= m_isnakelen - 1; i++) {
    Snake::locate(snake[i].x, snake[i].y);
    cout << '*';
  }
}