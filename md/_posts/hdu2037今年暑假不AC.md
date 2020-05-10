---
title: hdu2037今年暑假不AC
categories: 
- Algorithm
tags: 
- 博客
---
***所谓贪心，只是人的一种本能反应***

[原题链接](http://acm.hdu.edu.cn/showproblem.php?pid=2037)

````cpp
#include <algorithm>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//各个节目的开始时间，结束时间！
struct Ti {
  int Ti_s;
  int Ti_e;
};

//自定义排序规则cmp
bool cmp(Ti a, Ti b) { return a.Ti_e < b.Ti_e; }

int main() {
  Ti *T = new Ti[102];
  int n;
  while (cin >> n) {
    if (n == 0) break;
    for (int i = 0; i < n; i++) {
      cin >> T[i].Ti_s >> T[i].Ti_e;
    }
    std::sort(T, T + n, cmp);  //对结构体的Ti_e排序，自定义排序规则
    // for (int i = 0; i < n; i++) {
    //   cout << T[i].Ti_s << " " << T[i].Ti_e << endl;
    // }
    int cnt = 1, x = T[0].Ti_e;
    for (int i = 1; i < n; i++) {
      //如果第一个节目结束，第二个节目已经开始了，更新变量x，并且又看一个节目！
      if (T[i].Ti_s >= x) {
        cnt++;
        x = T[i].Ti_e;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
````
**才疏学浅，望雅正！**