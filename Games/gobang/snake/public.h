#ifndef _PUBLIC_H_
#define _PUBLIC_H_
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

struct node {
  int x;
  int y;
} snake[1000];

class Snake {
public:
  Snake(int _m, int _n, int _snakelen);
  ~Snake();
  void print_wall(); // print wall
  void locate(int x, int y);
  void hide();                             // Hide the cursor
  double random(double start, double end); // Generate random number
  void print_snake();                      // print snake

private:
  int m_im, m_in, m_isnakelen;
};

#endif