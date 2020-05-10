---
title: 每天一个linux终端命令shutdown命令(2)
categories: 
- Linux
tags: 
- 博客
---
***我不树敌,敌自树***

**shutdown**中文就是关机的意思。

由于linux的关机和重新启动操作是很重大的系统操作,所以一般只有**root**(**超级用户**)才能执行,不过在一些linux发行版中,我们可以使用sudo增加用户权限来执行这些需要**root**身份才能执行的命令。

```bash
sudo shutdown [-krhc] [时间] [警告信息]
```

选项与参数介绍:

| 参数 |                         功能                         |
| :--: | :--------------------------------------------------: |
|  -k  |            不要真的关机,只是发出警告信息             |
|  -r  |          在将系统的服务停掉之后就重启(常用)          |
|  -h  |         将系统的服务停掉之后,立即关机(常用)          |
|  -c  |           取消已经在进行的shutdown命令内容           |
| 时间 | 指定系统关机的时间,若没有这个项目,则默认一分钟后进行 |

范例:

```bash
sudo shutdown -h 10 'I will shutdown after 10 mins'
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200222141339960.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70) 

'I will shutdown after 10 mins'
会提示其它使用者这台电脑将在10分钟后关机,请做好保存工作!
 还有个常用的重启命令**reboot**

```bash
sync; sync; sync; reboot
```

**sync**会使在内存中尚未更新的数据,被写入磁盘中。
 每天一个linux终端命令,积少成多,希望大家越来越优秀!
 **才疏学浅，望雅正！**