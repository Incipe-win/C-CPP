---
title: 初学map的各种操作
categories: 
- Cpp
tags: 
- 博客
---
```cpp
/*
 * @Author: incipe
 * @Date: 2019-09-22 23:14:53
 * @LastEditTime: 2019-10-21 21:35:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath:
 */
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <utility>

std::map<std::string, std::string> mp;
void init() { //输出，初始化
  using namespace std;
  ofstream file;
  file.open("1.txt");
  map<string, string>::iterator it;
  for (it = mp.begin(); it != mp.end(); it++)
    file << it->first << " " << it->second << endl;
  file.close();
}

void Find() { //查找学生
  using namespace std;
  cout << "请输入要查找人的学号:";
  string id;
  cin >> id;
  map<string, string>::iterator it;
  it = mp.find(id);
  if (it == mp.end()) {
    cout << "查无此人！" << endl;
  } else {
    cout << "查找成功！" << endl;
    cout << "他的名字是:" << it->second << endl;
  }
}
void alter() { //删除学生信息
  using namespace std;
  // std::ofstream file;
  // file.open("1.txt");
  cout << "请输入要修改的学号：";
  string id;
  cin >> id;
  map<string, string>::iterator it;
  it = mp.find(id);
  if (it != mp.end()) {
    cout << "查找成功，名字是：" << it->second;
    cout << "\n是否删除? yes:no: ";
    string temp;
    while (1) {
      cin >> temp;
      if (temp == "yes" || temp == "YES") {
        mp.erase(id);
        init();
        cout << "删除成功！" << endl;
        break;
        // file.close();
      } else if (temp == "no" || temp == "NO") {
        cout << "您已经取消修改" << endl;
        break;
      } else {
        cout << "输入非法，请重新输入!" << endl;
        continue;
      }
    }
  } else {
    cout << "没有这个人！" << endl;
  }
}

void print() { //打印学生信息
  using namespace std;
  // ifstream file;
  // file.open("1.txt");
  cout << "如下所示：" << endl;
  map<string, string>::iterator it;
  for (it = mp.begin(); it != mp.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }
  // file.close();
}

void Insert() { //插入学生信息
  using namespace std;
  map<string, string>::iterator it;
  cout << "请输入要插入同学的学号：";
  string temp1, temp2;
  while (1) {
    cin >> temp1;
    it = mp.find(temp1);
    if (it != mp.end()) {
      cout << "此学号已经存在了，请重新输入！" << endl;
      continue;
    } else {
      break;
    }
  }
  cout << "请输入要插入同学的姓名：";
  cin >> temp2;
  mp.insert(make_pair(temp1, temp2));
  init();
}

int main() {
  using namespace std;
  mp["xxxxxxxx00"] = "xx1";
  mp["xxxxxxxx01"] = "xx2";
  mp["xxxxxxxx02"] = "xx3";
  mp["xxxxxxxx03"] = "xx4";
  mp["xxxxxxxx04"] = "xx5";
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  // cout.tie(0);
  cout << "欢迎来到XXXXXX班级管理系统！" << endl;
  init();
  cout << "生成班级成员数据成功！" << endl;
  while (1) {
    cout << "1:查找" << endl;
    cout << "2:删除" << endl;
    cout << "3:插入" << endl;
    cout << "4:打印" << endl;
    cout << "5.退出" << endl;
    cout << "6.清屏" << endl;
    cout << "请选择:";
    int n;
    cin >> n;
    if (n == 5) {
      cout << "感谢您的使用，祝您生活愉快！" << endl;
      break;
    }
    switch (n) {
    case 1:
      Find();
      break;
    case 2:
      alter();
      break;
    case 3:
      Insert();
      break;
    case 4:
      print();
      break;
    case 6:
      system("cls");
      break;
    default:
      cout << "输入非法！" << endl;
      continue;
    }
  }
  cin.get();
  return 0;
}
// map是自动排序的，数字按大小，字符串按字典顺序
```