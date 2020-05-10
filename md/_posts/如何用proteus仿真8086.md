---
title: 如何用proteus仿真8086
categories: 
- 软件使用
tags: 
- 博客
---
***岁月不饶人，我亦未曾饶过岁月。***

## 1.需要的工具
proteus
*过低版本不可以仿真8086，请下载7.8版本及以上的*
[下载地址(附教程)](https://pan.baidu.com/s/1ANBzX668f9rVUAPKMASRLQ)
提取码：rh8j

emu8086
[官网地址](https://emu8086-microprocessor-emulator.en.softonic.com/download)
[网盘地址](https://pan.baidu.com/s/1UWKSyGCCOXgZ8fdwbS3fVA )
提取码：j5qn
## 2.编译汇编代码
打开emu8086
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191231093207807.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191231093228694.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
选择默认的即可。
*也可以生成.exe或者.bin文件*
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191231093402948.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
添加好你的代码，点compile
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191231093446176.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
如果代码没有错误会弹出这个窗口，你可以重命名或者更改文件位置。
*如果点的默认，那么这个文件在emu8086安装位置的MyBuild里面会有*

## 3.给proteus添加可执行文件
打开proteus
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191231093957703.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
会弹出来如下窗口
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191231094537245.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
按照图示更改好，即可
![在这里插入图片描述](https://img-blog.csdnimg.cn/2019123109461392.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
最后点击Execute，如果代码没错，仿真图连接的没有问题，就可以看到仿真结果了。

**才疏学浅，望雅正！**