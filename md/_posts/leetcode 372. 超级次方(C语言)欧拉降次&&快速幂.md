---
title: leetcode 372. 超级次方(C语言)欧拉降次&&快速幂
categories: 
- Algorithm
tags: 
- 博客
---
题目链接：[超级次方](https://leetcode-cn.com/problems/super-pow/)

一开始直接用快速幂，结果直接超时。
```cpp
long long FastPow(long long a,long long c)
{
    long long res=1;
    while(c)
    {
        if(c&1)
        {
            res*=a;
            res%=1337;
        }
        a*=a;
        a%=1337;
        c>>=1;
    }
    return res;
}

int superPow(int a, int* b, int bSize){
    long long count,c=0;
    for(int i=0;i<bSize;i++)
        c+=(b[i]*pow(10,(bSize-i-1)));
    //printf("%d ",c);
    count=FastPow(a,c);
    return count;
}

```
欧拉降幂公式：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190818155329442.png)
Φ（c）是欧拉函数
详情请看：[欧拉函数](https://baike.baidu.com/item/%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B0)

求法如下：

```cpp
int eular(int n)
{
    int ret=1,i;
    for(i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            n/=i;
            ret*=i-1;
            while(n%i==0)
            {
                n/=i;
                ret*=i;
            }
        }
    }
    if(n>1)
        ret*=n-1;
    return ret;
}
```
欧拉函数求出来了，直接A题，代码如下：

```cpp
long long FastPow(long long a,long long c)
{
    long long res=1;
    a%=1337;
    while(c)
    {
        if(c&1)
        {
            res*=a;
            res%=1337;
        }
        a*=a;
        a%=1337;
        c>>=1;
    }
    return res;
}

int eular(int n)
{
    int ret=1,i;
    for(i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            n/=i;
            ret*=i-1;
            while(n%i==0)
            {
                n/=i;
                ret*=i;
            }
        }
    }
    if(n>1)
        ret*=n-1;
    return ret;
}

int superPow(int a, int* b, int bSize){
    int n = 0,temp;
    temp=eular(1337);
    if(bSize==0){
        return 0;
    }
    for(int i=0;i<bSize;i++){
        n*=10;
        n+=b[i];
        n%=temp;
        n+=temp;
    }
    return FastPow(a,n);
}
```



