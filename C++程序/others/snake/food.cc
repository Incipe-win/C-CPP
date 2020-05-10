#include "food.h"
#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy2(HANDLE hOut2, int x, int y) {
  COORD pos;
  pos.X = x;
  pos.Y = y;
  SetConsoleCursorPosition(hOut2, pos);
}
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);

Food::Food(Wall &tempWall) : wall(tempWall) {}

void Food::setFood() {
  // 不断地随机产生食物
  while (true) {
    foodX = rand() % (Wall::ROW - 2) + 1;
    foodY = rand() % (Wall::COL - 2) + 1;
    if (wall.getWall(foodX, foodY) == ' ') {
      wall.setWall(foodX, foodY, '#');
      gotoxy2(hOut2, foodY * 2, foodX);
      cout << "#";
      break;
    }
  }
}