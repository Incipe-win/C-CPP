#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_M = 101;
const int MAX_N = 101;  //最大油田面积
char ch[MAX_M][MAX_N];  //油田
int m, n;

void dfs(int, int);

int main() {
  while (cin >> m >> n) {
    if (m == 0 && n == 0) break;
    for (int i = 0; i < m; i++) {
      cin >> ch[i];
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (ch[i][j] == '@') {
          dfs(i, j);
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

void dfs(int x, int y) {
  ch[x][y] = '*';
  for (int nx = -1; nx <= 1; ++nx) {
    for (int ny = -1; ny <= 1; ++ny) {
      int dx = nx + x, dy = ny + y;
      if (0 <= dx && dx < m && 0 <= dy && dy < n && ch[dx][dy] == '@') {
        dfs(dx, dy);
      }
    }
  }
  return;
}