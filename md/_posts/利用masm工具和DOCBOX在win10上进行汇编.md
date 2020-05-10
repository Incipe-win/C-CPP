---
title: 利用masm工具和DOCBOX在win10上进行汇编
categories: 
- 汇编
tags: 
- 博客
---
windows XP直接用cmd就可以了，win10用户也可也在虚拟机上装个XP进行汇编！

接下来介绍利用masm工具和DOCBOX在win10上进行汇编

# 1.[DOCBOX下载地址](https://www.dosbox.com/download.php?main=1)

MASM32下载地址
[官网](http://www.masm32.com/)

网盘地址
链接：https://pan.baidu.com/s/172uIe8oT28-r27I93KbKxA 
提取码：ugyp 

# 2.安装DOCBOX

1）运行，一路next即可。

2）在另一个盘创建个专门汇编的文件夹，列如：E:\Assembly。

3）把网盘下载的masm工具放该文件夹，或者直接解压官网的masm32v11r，安装后直接用gedit.exe程序编写、编译和链接asm汇编程序。

4）点击桌面的DOCbox0.74-3。

```
mount c E:\Assembly
c:
cd 汇编文件目录
```
5）不想每次都输入上步骤，可这样
在DOCBOX安装目录下找到DOSBox 0.74 Options.bat
在弹出来的文档最下面输入

```
mount c E:\Assembly
path=%path%; \asm
```
asm是在Assembly下保存汇编的文件夹，另外一个masm是用来保存汇编工具的。
接下来就可以进行汇编了。
alt+enter全屏模式！
列如

```
cd /asm
masm test,asm
敲入回车
敲入回车
敲入回车
link test.obj
debug test.exe
```
详情可以参考[传送门](https://blog.csdn.net/YuzuruHanyu/article/details/80287419)