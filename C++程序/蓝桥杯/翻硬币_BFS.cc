#include <math.h>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;
char a[1005], b[1005];

struct node {
  char ff[1005];
  int step;
};

void bfs() {

  queue<node> q;
  node ll;
  strcpy(ll.ff, a);
  ll.step = 0;
  q.push(ll);
  while (!q.empty()) {
    node tmp;
    tmp = q.front();
    q.pop();
    if (!strcmp(tmp.ff, b)) {
      printf("%d\n", tmp.step);

      return;
    }
    int num = strlen(tmp.ff);
    for (int i = 0; i < num - 1; i++) {
      node now;
      now = tmp;
      now.step++;
      if (now.ff[i] == '*')
        now.ff[i] = 'o';
      else
        now.ff[i] = '*';
      if (now.ff[i + 1] == '*')
        now.ff[i + 1] = 'o';
      else
        now.ff[i + 1] = '*';

      q.push(now);
    }
  }
}

int main() {

  while (~scanf("%s", a)) {
    scanf("%s", b);

    bfs();
  }

  return 0;
}