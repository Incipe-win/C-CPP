#ifndef WALL_H_
#define WALL_H_
#include <iostream>
using namespace std;

class Wall {
public:
  enum { ROW = 26, COL = 26 };
  // 初始化墙壁
  void initWall();
  // 打印墙
  void drawWall();

  // 设置当前位置的内容
  void setWall(int x, int y, char c);
  // 获取当前位置
  char getWall(int x, int y);

private:
  char gameArray[ROW][COL];
};

#endif // WALL_H_