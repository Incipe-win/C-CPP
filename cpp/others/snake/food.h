#ifndef FOOD_H_
#define FOOD_H_
#include "wall.h"
#include <iostream>

using namespace std;

class Food {
public:
  Food(Wall &tempWall);
  void setFood();

private:
  // 食物坐标
  int foodX;
  int foodY;
  Wall &wall;
};

#endif // FOOD_H_