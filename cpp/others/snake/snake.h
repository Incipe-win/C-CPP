#ifndef SNAKE_H_
#define SNAKE_H_
#include "food.h"
#include "wall.h"
#include <iostream>

using namespace std;

class Snake {
public:
  // 移动按键
  enum { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };
  Snake(Wall &tempWall, Food &tmepFood);

  //初始化蛇
  void initSnake();

  // 蛇移动的时候销毁节点, 要清楚所有节点, 再画蛇.
  void destroyPoint();
  // 吃到食物添加节点
  void addPoint(int x, int y);
  // 蛇移动的时候删除节点
  // 比如: ##@->###@, 销毁最后一个#,因为没吃到食物
  void delPoint();
  //蛇移动
  bool move(char key);
  // 设置蛇移动的速度, 就是设置sleep的时长
  int getSleepTime();
  // 获取蛇长度,蛇越长,sleep睡眠越短
  int countList();
  // 获取分数
  int getScore();

private:
  //蛇链表
  struct Point {
    int x;
    int y;
    Point *next;
  };
  Point *pHead;
  Wall &wall;
  Food &food;
  // 是否头尾连接,循环移动
  bool isRool;
};

#endif // SNAKE_H_