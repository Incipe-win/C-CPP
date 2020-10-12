#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  //不加会超时，难搞。
  int n;
  cin >> n;
  while (n--) {
    int length, numbers;
    cin >> length >> numbers;
    vector<int> ants;
    for (int i = 0; i < numbers; i++) {
      int tmp;
      cin >> tmp;
      ants.push_back(tmp);
    }
    int minT = 0, maxT = 0;
    /* 最短时间，相遇的蚂蚁，保持原样继续前进不会有问题。
     */
    for (int i = 0; i < numbers; i++) {
      int remain = length - ants[i];
      minT = std::max(minT, std::min(ants[i], remain));
    }
    /* 最长时间，往同一个方向走。找两端蚂蚁，看谁的距离长！
     */
    for (int i = 0; i < numbers; i++) {
      int remain = length - ants[i];
      maxT = std::max(maxT, std::max(ants[i], remain));
    }
    cout << minT << " " << maxT << endl;
  }
  return 0;
}

/*此题主要考的是思维方法*/