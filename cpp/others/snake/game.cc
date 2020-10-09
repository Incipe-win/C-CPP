#include "food.h"
#include "snake.h"
#include "wall.h"
#include <conio.h>
#include <ctime>
#include <iostream>
#include <windows.h>

using namespace std;

// 定位光标
void gotoxy(HANDLE hOut, int x, int y) {
  COORD pos;
  pos.X = x;
  pos.Y = y;
  SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

int main() {
  srand((unsigned)time(nullptr));
  bool isDead = false; // 是否死亡
  char preKey = '\0';  // 前一个按键的内容

  Wall w;
  w.initWall();
  w.drawWall();

  Food f(w);
  f.setFood();

  Snake s(w, f);
  s.initSnake();

  gotoxy(hOut, 0, Wall::ROW);
  cout << "Score: " << s.getScore() << endl;
  // gotoxy(hOut, 10, 5);

  while (!isDead) {
    char key = _getch(); // 获取按键
    // 防止一开始按a(左), 直接结束游戏
    if (key == s.LEFT && preKey == '\0') {
      continue;
    }
    do {
      // 消除其他按键, 只有asdw四个按键有用
      if (key == s.UP || key == s.DOWN || key == s.LEFT || key == s.RIGHT) {
        // 防止蛇180死亡
        if ((key == s.LEFT && preKey == s.RIGHT) ||
            (key == s.RIGHT && preKey == s.LEFT) ||
            (key == s.UP && preKey == s.DOWN) ||
            (key == s.DOWN && preKey == s.UP)) {
          // 按照上一个按键继续移动
          key = preKey;
        } else {
          preKey = key;
        }
        // 如果没有撞到墙壁
        if (s.move(key) == true) {
          // 清空屏幕, 重新打印墙壁
          // system("cls");
          // w.drawWall();
          // 解决每次刷屏的闪烁
          gotoxy(hOut, 0, Wall::ROW);
          cout << "Score: " << s.getScore() << endl;
          // 游戏难度
          Sleep(s.getSleepTime());
        } else {
          // 转到墙壁, 或者自己, 死亡
          isDead = true;
          break;
        }
      } else {
        // 游戏刚开始按a(左)不起作用
        key = preKey;
      }

    } while (!_kbhit()); // 如果没有按键按下, 按照前一个按键一直移动
  }
  system("pause");
  return 0;
}