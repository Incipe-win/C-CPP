---
title: 每天一个linux终端命令ch命令(4)
categories: 
- Linux
tags: 
- 博客
---
***好读书，不求甚解；每有会意，便欣然忘食。*** 

*ch*命令指的是 **chgrp,chown,chmod**这一组命令! 因为分开缺少连贯性,所以凑一起了。

- **chgrp**修改文件所属的用户组
- **chown**修改文件的拥有者
- **chmod**修改文件的属性

chgrp和chown用法基本一致。

```bash
chgrp [-R] dirname/filename ...
chown [-R] 账号名称 文件或目录
chown [-R] 账号名称:用户组名称 文件或目录
chmod [-R] xyz 文件或者目录
```

-R进行递归(recursive)修改,即连同子目录下的所有文件,目录都更新成为这个用户组(用户)，简言之,就是修改目录内所有文件。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200224134116955.png) ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200224133722573.png) ![在这里插入图片描述](https://img-blog.csdnimg.cn/2020022413385138.png) 

*用户组信息在 **/etc/group**下。* *用户信息在 **/home**下,或者到 **/etc/passwd**也可以查看。*

 如图,我的linux中我创建了两个用户以及两个同名的用户组。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200224134751654.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70) 

**chmod**用法 1.py文件的文件权限字符为【-rw-r- -r- -】 这九个权限三个三个一组，我们可以用数字来代表各个权限。

- r：4
- w：2
- x：1

例如，我们要把1.py权限修改为【-rwxrwxrwx】 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200224140054988.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70) 

**chmod**还有如下使用方法：

| chmod<br> | u<br> g <br>  o <br>  a <br> | +(加入)<br> -(移除)<br> =(设置) <br> | r<br>   w <br>   x <br> | 文件或目录 |
| :-------: | :--------------------------: | :----------------------------------: | :---------------------: | :--------: |
|           |                              |                                      |                         |            |

- u(user)用户权限
- g(group)组成员权限
- o(others)其它用户权限
- a(all)所有的 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200224143227333.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)

每天一个linux终端命令,积少成多,希望大家越来越优秀!

**才疏学浅，望雅正！**