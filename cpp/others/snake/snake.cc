#include "snake.h"
#include <iostream>
#include <windows.h>

void gotoxy1(HANDLE hOut1, int x, int y) {
  COORD pos;
  pos.X = x;
  pos.Y = y;
  SetConsoleCursorPosition(hOut1, pos);
}
HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

Snake::Snake(Wall &tempWall, Food &tempFood) : wall(tempWall), food(tempFood) {
  pHead = nullptr;
  isRool = false;
}

// 销毁节点
void Snake::destroyPoint() {
  Point *pCur = pHead;
  while (pHead != nullptr) {
    pCur = pHead->next;
    delete pHead;
    pHead = pCur;
  }
}

// 添加节点
void Snake::addPoint(int x, int y) {
  Point *newPoint = new Point;
  newPoint->x = x;
  newPoint->y = y;
  newPoint->next = nullptr;

  if (pHead != nullptr) {
    wall.setWall(pHead->x, pHead->y, '=');
    gotoxy1(hOut1, pHead->y * 2, pHead->x);
    cout << "=";
  }
  newPoint->next = pHead;
  pHead = newPoint;
  wall.setWall(pHead->x, pHead->y, '@');
  gotoxy1(hOut1, pHead->y * 2, pHead->x);
  cout << "@";
}

// 初始化蛇
void Snake::initSnake() {
  destroyPoint();
  addPoint(5, 3);
  addPoint(5, 4);
  addPoint(5, 5);
}

// 删除节点
void Snake::delPoint() {
  if (pHead == nullptr || pHead->next == nullptr) {
    return;
  }
  Point *pCur = pHead->next;
  Point *pPre = pHead;
  while (pCur->next != nullptr) {
    pPre = pPre->next;
    pCur = pCur->next;
  }
  wall.setWall(pCur->x, pCur->y, ' ');
  gotoxy1(hOut1, pCur->y * 2, pCur->x);
  cout << " ";
  delete pCur;
  pCur = nullptr;
  pPre->next = nullptr;
}

// 蛇移动
bool Snake::move(char key) {
  int x = pHead->x;
  int y = pHead->y;
  switch (key) {
  case UP:
    --x;
    break;
  case DOWN:
    ++x;
    break;
  case LEFT:
    --y;
    break;
  case RIGHT:
    ++y;
    break;
  default:
    break;
  }
  /**
   * 头尾相接不会挂, 可以循环移动
   */
  Point *pCur = pHead->next;
  Point *pPre = pHead;
  while (pCur->next != nullptr) {
    pPre = pPre->next;
    pCur = pCur->next;
  }
  if (pCur->x == x && pCur->y == y) {
    isRool = true;
  } else {
    // 碰到墙壁,或者吃到自己
    if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=') {
      addPoint(x, y);
      delPoint();
      system("cls");
      wall.drawWall();
      cout << "Score: " << getScore() << endl;
      cout << "GAME OVER!" << endl;
      return false;
    }
  }

  // 如果吃到食物
  if (wall.getWall(x, y) == '#') {
    addPoint(x, y);
    food.setFood();
  } else {
    addPoint(x, y);
    delPoint();
    // 防止删除蛇头
    if (isRool) {
      wall.setWall(x, y, '@');
      gotoxy1(hOut1, y * 2, x);
      cout << "@";
    }
  }
  return true;
}

int Snake::getSleepTime() {
  int sleepTime = 0;
  int size = countList();
  if (size < 5) {
    sleepTime = 300;
  } else if (size >= 5 && size <= 8) {
    sleepTime = 200;
  } else {
    sleepTime = 100;
  }
  return sleepTime;
}

int Snake::countList() {
  int size = 0;
  Point *curPoint = pHead;
  while (curPoint != nullptr) {
    ++size;
    curPoint = curPoint->next;
  }
  return size;
}

int Snake::getScore() {
  int size = countList();
  int score = (size - 3) * 100;
  return score;
}