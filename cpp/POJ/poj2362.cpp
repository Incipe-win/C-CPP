#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
// square表示边长，vis表示节点，length表示能构成正方形的边长。
int square[30], vis[30], length, nums;

// side是第几条边，pos是当前边比length小，访问的下一个边，len只是一个临时变量，目的是计算边长。
bool dfs(int side, int pos, int len) {
  if (side == 4) {
    return true; //结束递归！
  }
  for (int i = pos; i >= 1; i--) {
    if (!vis[i]) {
      //有没有被访问过！
      if (square[i] + len < length) {
        vis[i] = 1; //标记访问过了！
        //递归，长度不够，加长度。此处不能写pos-1，因为可能第二次以后长度还会不够。
        if (dfs(side, i - 1, square[i] + len)) {
          return true; //结束调用
        }
        vis[i] = 0;
      } else if (square[i] + len == length) {
        vis[i] = 1;                   //标记
        if (dfs(side + 1, nums, 0)) { //递归，长度够了，判断下一条边。
          return true;
        }
        vis[i] = 0; //复位，以免影响另一条边遍历。
      }
    }
  }
  return false; //到最后都没有找到，结束！
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int sum = 0;
    cin >> nums;
    for (int i = 1; i <= nums; i++) {
      cin >> square[i];
      sum += square[i];
    }
    if (sum % 4 != 0) {
      cout << "no" << endl;
      continue;
    }
    length = sum / 4;
    fill(vis, vis + 30, 0); //确保都没被访问过！
    //排个序，不然结果不对。
    sort(square + 1, square + 1 + nums);
    // for (int i = 1; i <= nums; i++)
    //   cout << square[i] << " ";
    // cout << endl;
    if (dfs(0, nums, 0)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}