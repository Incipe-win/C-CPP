#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

const int N = 1100, M = 1100;

using namespace std;

int n, l, m, father[N * M * 2];
int a[N][M];

struct node {
  int src, dst;
  int val;
} node[N * M * 2];

int findFather(int a) {
  while (a != father[a]) {
    a = father[a];
  }
  return a;
}

void init() {
  for (int i = 1; i <= n * m * 2; ++i) {
    father[i] = i;
  }
}

int unionSet(int x, int y) {
  int fx = findFather(x);
  int fy = findFather(y);
  if (fx != fy) {
    father[fx] = fy;
    return 1;
  }
  return 0;
}
