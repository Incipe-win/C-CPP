---
title: 关于memset
categories: 
- Algorithm
tags: 
- 博客
---
被不了解memset狠狠的坑了一把，难受。

对于整型数组，若要是初始化为非0的值时应该使用for循环，
字符型或0，用memset即可。

列如：

```cpp
#include<bits/stdc++.h>
int main()
{
    int s[100];
    memset(s,1,sizeof(s));
    for(int i=0;i<100;i++)
        std::cout<<s[i]<<" ";
    return 0;
}

```
这样子是达不到预期效果的，因为memset函数的作用是把一整块内存区域全部填充为某个特定的值，填充的时候是一个字节一个字节进行填充的。
参考：
[https://blog.csdn.net/melody_1016/article/details/83479778](https://blog.csdn.net/melody_1016/article/details/83479778)
[http://www.cplusplus.com/reference/cstring/memset/](http://www.cplusplus.com/reference/cstring/memset/)

对于字符型：

```cpp
#include<bits/stdc++.h>
int main()
{
    char s[100];
    memset(s,'1',sizeof(s)/sizeof(s[0]));
    for(int i=0;i<100;i++)
        std::cout<<s[i]<<" ";
    return 0;
}

```
用memset是可以的。
初始化数组还可以用C++的fill或者fill_n

fill:
```cpp
#include<bits/stdc++.h>
int main()
{
    int s[100];
    std::fill(s,s+100,11111);
    for(int i=0;i<100;i++)
        std::cout<<s[i]<<" ";
    return 0;
}

```
fill_n:

```cpp
#include<bits/stdc++.h>
int main()
{
    int s[100];
    std::fill_n(s,100,11111);//第一个是数组名，第二个是个数，第三个是填充值
    for(int i=0;i<100;i++)
        std::cout<<s[i]<<" ";
    return 0;
}

```
详情请参考：
[http://www.cplusplus.com/reference/algorithm/fill_n/?kw=fill_n](http://www.cplusplus.com/reference/algorithm/fill_n/?kw=fill_n)
[http://www.cplusplus.com/reference/algorithm/fill/?kw=fill](http://www.cplusplus.com/reference/algorithm/fill/?kw=fill)