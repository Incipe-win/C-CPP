---
title: 给虚拟机的Ubuntu换阿里源
categories: 
- Linux
tags: 
- 博客
---
安装的Ubuntu安装东西速度实在是不敢恭维QAQ，因为是国外的网址。
所以我们要换成国内的源，然后就可以尽情飞越了。

首先我们还是要先备份下：`sudo cp /etc/apt/sources.list /etc/apt/sources.list.bak`
接下来：`sudo vim /etc/apt/sources.list`
然后把里面的东西全删除，
我们来到[https://opsx.alibaba.com/mirror](https://opsx.alibaba.com/mirror)
找到Ubuntu，把里面内容换成如下：

```c
deb http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse
```

然后

```
sudo apt-get update
sudo apt-get upgrade
```
就OK了。