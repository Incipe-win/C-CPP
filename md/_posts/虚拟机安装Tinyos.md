---
title: 虚拟机安装Tinyos
categories: 
- IOT
tags: 
- 博客
---

## 讲在前面的话

不建议大家用虚拟机ubuntu18.04LTS安装Tinyos，很多坑。

弄了好久，最后编译还各种无法解决的错误，还望各位不吝赐教！

[Vmware下载]([https://incipe-win.github.io/2020/03/13/%E8%99%9A%E6%8B%9F%E6%9C%BA%E5%AE%89%E8%A3%85Ubuntu18.04/](https://incipe-win.github.io/2020/03/13/虚拟机安装Ubuntu18.04/))

[推荐系统Debain](https://mirrors.aliyun.com/deepin-cd/15.11/deepin-15.11-amd64.iso)

## 准备环境

### 1. 搭建java环境

[Ubuntu(Debian)安装教程](https://cloud.tencent.com/developer/article/1162527)

### 2. 搭建python开发环境和g++编译工具

````bash
sudo apt-get install python2.7-dev
sudo apt-get install gcc
sudo apt-get install g++
sudo apt-get install gcc-msp430
````

## 1. Tell apt about the TinyProd Signing Key.

告诉apt TinyProd签名密钥

````bash
wget -O - http://tinyprod.net/repos/debian/tinyprod.key | sudo apt-key add -
````

## 2. 添加Tinyos源

````bash
sudo -s
cd /etc/apt/sources.list.d
echo "deb http://tinyprod.net/repos/debian wheezy main" >> tinyprod-debian.list
echo "deb http://tinyprod.net/repos/debian msp430-46 main" >> tinyprod-debian.list
````

最后两句的意思是把"deb http://tinyprod.net/repos/debian wheezy main"重定向到tinyprod-debian.list文件

## 3. 更新源并且安装tinyos依赖包

````bash
sudo apt-get update
sudo apt-get install nesc tinyos-tools
````

这个过程可能有点长，请耐心等待！

## 4. 下载Tinyos源代码

````bash
wget http://github.com/tinyos/tinyos-release/archive/tinyos-2_1_2.tar.gz  
tar xf tinyos-2_1_2.tar.gz 
````

你可以将tinyos-release-tinyos-2_1_2文件命名为tinyos-main或者其它。

移动到个自己熟悉的地方保存起来。

## 5. 建立.env或者.sh文件

快速启动Tinyos

在tinyos-main目录下

````bash
vim tinyos.env
````

添加如下内容

````sh
# Here we setup the environment
# variables needed by the tinyos 
# make system

export TOSROOT="<local-tinyos-path>"
export TOSDIR="$TOSROOT/tos"
export CLASSPATH=.:$CLASSPATH:$TOSROOT/support/sdk/java/tinyos.jar
export MAKERULES="$TOSROOT/support/make/Makerules"
export PYTHONPATH=$PYTHONPATH:$TOSROOT/support/sdk/python:PYTHONPATH
echo "setting up TinyOS on source path $TOSROOT"
export CPATH=:/usr/include/python2.7/
````

这里的 **< local-tinyos-path>**替换成自己tinyos-main的路径。

添加shell访问

1. 让其(tinyos.env)作为root用户放在/etc/profile.d/下
2. 添加到.bsahrc

这里采用第二种方法

如果安装了zsh就是添加到.zshrc

````bash
vim ~/.zshrc
````

添加source < local-tinyos-path>/tinyos.env 

同理，这里的< local-tinyos-path>也是tinyos-main的安装路径。

重启终端，终端输出setting up TinyOS on source path < local-tinyos-path>即说明添加成功！

## 4. 检查是否安装成功

````bash
tos-check-env
````

查看选项 nesc 、java 以及 graphviz 是否已经正确安装。

打开仿真程序目录下的 **Blink** 仿真程序

````bash
cd /opt/tinyos-main/apps/Blink
````

编译示例程序

````bash
make telosb（编译不添加仿真）
或者
make telosb sim（编译添加仿真）
````

## 可能出现的问题

````bash
$make micaz sim
mkdir -p simbuild/micaz
make: python2.5-config: Command not found
make: python2.5-config: Command not found
make: python2.5-config: Command not found
````

请确定安装好的python2.7

打开tinyos-main文件

搜索：**"sim.extra"**，打开更改

>PYTHON_VERSION ?= $(shell python --version 2>&1 | sed 's/Python 2\.\([0-9]\)\.[0-9]+\{0,1\}/2.\1/')

为：

>PYTHON_VERSION ?= $(shell python --version 3>&1 | sed 's/Python 2\.\([0-9]\)\.[0-9]+\{0,1\}/2.\1/')

有其它问题可以自行谷歌😂。

## 参考链接

[https://askubuntu.com/questions/799603/install-tinyos-on-ubuntu](https://askubuntu.com/questions/799603/install-tinyos-on-ubuntu)

[https://stackoverflow.com/questions/34139897/make-python2-5-config-command-not-found-error-on-tinyos/50547278](https://stackoverflow.com/questions/34139897/make-python2-5-config-command-not-found-error-on-tinyos/50547278)

[https://github.com/tinyos/tinyos-main/issues/289](https://github.com/tinyos/tinyos-main/issues/289)

[http://tinyos.stanford.edu/tinyos-wiki/index.php/Automatic_installation](http://tinyos.stanford.edu/tinyos-wiki/index.php/Automatic_installation)