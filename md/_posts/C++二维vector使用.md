---
title: C++二维vector使用
categories: 
- Cpp
tags: 
- 博客
---

***你再不来，我要下雪了。***



 记录下二维vector的遍历（输出）
 *注：二维vector的赋值不能跟二维数组一样用scanf或者cin写入*

 **<font color="#0099ff" >遍历（迭代器）</font>**
 *方法一*
 ````cpp
void print() {
  vector<vector<char>>::iterator it;
  vector<char>::iterator iter;
  vector<char> ch;
  for(it = res.begin(); it != res.end(); ++it) {
    ch = *it;
    for (iter = ch.begin(); iter != ch.end(); ++iter) {
      cout << *iter << " ";
    }
  }
  cout << endl;
}
 ````
 *方法二*
 ````cpp
 void print() {
  for (int i = 0; i < res.size(); ++i) {
  	for (int j = 0; j < res[0].size(); ++j) {
  		cout << res[i][j] << " ";
  	}
  }
  cout << endl;
}
 ````
 ***才疏学浅，望雅正！***
