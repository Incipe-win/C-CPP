#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_N = 102;
const int MAX_M = 102;
int n, m;
char ch[MAX_N][MAX_M];  //田的最大面积

void dfs(int, int);

int main() {
  //田的大小
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> ch[i];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      //从找到的第一个W开始dfs，把所有邻接的部分都用.表示，dfs了几次，就有几处池塘！
      if (ch[i][j] == 'W') {
        dfs(i, j);
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}

void dfs(int x, int y) {
  //把当前位置改为.
  ch[x][y] = '.';
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      //向x方向，y方向移动，相当于上下左右移动！
      int nx = x + dx, ny = y + dy;
      //判断（nx，ny）是否在田里面，并且是不是W!是的话，dfs。
      if (0 <= nx && nx < n && 0 <= ny && ny < m && ch[nx][ny] == 'W') {
        dfs(nx, ny);
      }
    }
  }
  return;
}