---
title: Ubuntu18.04安装
categories: 
- Linux
tags: 
- 博客
---
WSL就是Windows Subsystem for Linux（Windows系统的Linux子系统），因为依赖于win10，所以“子系统”会受到一些限制。
使用方法：
打开控制面板
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190827093214371.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190827093327299.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190827093446629.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/2019082709353178.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
按照提示重启就好了，要是没有这个选项，就说明系统不支持，建议升级系统。
重启后打开微软自带的应用商店，搜索WSL
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190827093830548.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190827093907882.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
选择一个，下载好了，运行就会自动安装的。
设置超级用户密码：`sudo passwd`
普通用户和超级用户切换
超级用户->普通用户：`su 用户名`
普通用户->超级用户：`su`
换源可以参考：[传送门](https://blog.csdn.net/qq_43826212/article/details/100068862)
更换字体不成功的情况可以参考：[传送门](https://blog.csdn.net/qq_43826212/article/details/100069168)