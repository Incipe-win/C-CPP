---
title: const int p 和 int const p
categories: 
- Cpp
tags: 
- 博客
---
主要讲下这两者的区别及用法！
**高能区**
>const int* p 和 int const* p是完全等价的！
>const int* const p 和 int const const* p 是完全等价的！

下面举几个例子来分析：
````cpp
int x = 100, y = 100;
const int* p = &x;
int* const m = &y;
p = &y;				//正确的，但是不要忘记&符号，因为此时的p代表的是地址！
*p = 10;			//错误！*p是常量！
*m = 100;			//正确，此时不要加&，因为此时的*x指的是x这个地址存放的变量！
m = &y;				//错误！x是常量
//如果是const int* const p;那么既不能修改*p也不能修改p
````
看看这些变量的关系！
| 变量名 | 存储地址 | 存储内容 |
| ------ | -------- | -------- |
| x      | &x       | 100      |
| p      | &p       | &x       |
| m      | &p       | &x       |

*从本质了解指针，可以学下汇编，或者读读《C和指针》这本书！*
才疏学浅，望雅正！