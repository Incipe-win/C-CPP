---
title: mingw-w64安装
categories: 
- 软件使用
tags: 
- 博客
---
如果在线安装的话，可能不会成功。

可以直接去**sourcegorge**[传送门](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-posix/sjlj/x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0.7z/download)下载离线包

也可以用百度网盘下载:[传送门](https://pan.baidu.com/s/19TDA4T1yVMK8shrExbtnvA) 
提取码：dzy3

**安装好后解压，添加环境变量即可。怎么添加环境变量下面的方法有介绍！**

这里讲下具体讲下用msys2安装mingw64
首先安装msys2，
可以去开源镜像站下载msys2。
当然，也可以去下面链接下载msys2：
链接：[传送门](https://pan.baidu.com/s/1VAxLlHAAoOtK2GeYWS2LVA )
提取码：zjos 

安装好后，还是先换源吧，不然装不了其它东西。
换源网上很多教程，我这里简单讲下：
找到\msys64\etc\pacman.d（安装目录下的）：
如图：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190820101545412.png)
对于mirrorlist.msys，贴上如下内容：

```
##
## MSYS2 repository mirrorlist
##
## Primary
## msys2.org
Server = http://mirrors.ustc.edu.cn/msys2/msys/$arch/
Server = http://repo.msys2.org/msys/$arch
Server = http://downloads.sourceforge.net/project/msys2/REPOS/MSYS2/$arch
Server = http://www2.futureware.at/~nickoe/msys2-mirror/msys/$arch/
```
mirrorlist.mingw64：

```
##
## 64-bit Mingw-w64 repository mirrorlist
##
## Primary
## msys2.org
Server = http://mirrors.ustc.edu.cn/msys2/mingw/x86_64/
Server = http://repo.msys2.org/mingw/x86_64
Server = http://downloads.sourceforge.net/project/msys2/REPOS/MINGW/x86_64
Server = http://www2.futureware.at/~nickoe/msys2-mirror/x86_64/
Server = http://mirror.bit.edu.cn/msys2/REPOS/
```
mirrorlist.mingw32：

```
##
## 32-bit Mingw-w64 repository mirrorlist
##
## Primary
## msys2.org
Server = http://mirrors.ustc.edu.cn/msys2/mingw/i686/
Server = http://repo.msys2.org/mingw/i686
Server = http://downloads.sourceforge.net/project/msys2/REPOS/MINGW/i686
Server = http://www2.futureware.at/~nickoe/msys2-mirror/i686/
```
保存之后就ok了。
msys2是依赖pacman的。
1.更新msys2的系统环境：

```
pacman -Sy
#更新源
pacman -Syu
pacman -Su
```
安装MinGW-w64 和 MinGW-x86版本：
一个是64位，另一个是32位。
简单讲下，x86，i686是32位的，x86，x86_64是64位的。

```
pacman -S  mingw-w64-i686-toolchain
pacman -S  mingw-w64-x86_64-toolchain

```
其它有需求者自装。
为mingw-w64添加环境变量：
安装成功后，在你的msys2的安装路径下会有mingw64文件夹的。
进去找到bin文件夹，复制整个bin文件夹的目录：D:\msys64\mingw64\bin
找到我的电脑（此电脑），右键属性，
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190820103721186.png)
点击高级系统设置，
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190820103800170.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
点击环境变量，
进去之后发现有个用户的变量，还有一个系统变量，简单讲就是：
**系统环境变量，对所有用户起作用,而用户环境变量只对当前用户起作用。** 
一般添加系统环境变量，找到Path，新建，把刚刚复制的路径粘贴进去就好了。
然后检查是否成功，win+r，输入cmd，键入g++ -v
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190820104430821.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
如上显示就是成功了。
如果是直接安装的mingw64
则是这样的
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191215173208208.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
一般用msys2安装的mingw64不带gdb，
用`pacman -S gdb`就可以了。
**才疏学浅，望雅正！**