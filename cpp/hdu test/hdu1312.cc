#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_W = 22;
const int MAX_H = 22;   //最大长方形
int w, h;               //长方形宽长
int cnt;                //满足条件的.的个数
char ch[MAX_W][MAX_H];  //长方形

void dfs(int x, int y);

int main() {
  while (cin >> w >> h) {
    if (w == 0 && h == 0) break;
    for (int i = 0; i < h; i++) {
      cin >> ch[i];
    }
    cnt = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        //从@开始
        if (ch[i][j] == '@') {
          dfs(i, j);
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

void dfs(int x, int y) {
  //每调用一次，cnt就加一，因为是找满足条件的.的个数
  cnt++;
  //标记
  ch[x][y] = '#';
  for (int nx = -1; nx <= 1; ++nx) {
    for (int ny = -1; ny <= 1; ++ny) {
      if (nx == ny || nx == -ny) {
        continue;
      }
      //题目要求只能上下左右移动，对角相邻没用！
      int mx = x + nx;
      int my = y + ny;
      //判断是否在长方形内，是否是.
      if (0 <= mx && mx < h && 0 <= my && my < w && ch[mx][my] == '.') {
        dfs(mx, my);
      }
    }
  }
  return;
}