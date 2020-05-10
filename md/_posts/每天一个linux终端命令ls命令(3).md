---
title: 每天一个linux终端命令ls命令(3)
categories: 
- Linux
tags: 
- 博客
---
***凡心所向，素履可往***



**ls**即list,译为列举。
**ls**可带参数,也可不带参数。可带的参数很多,这里只列举最常用的几种,有特殊需求可使用man或者--help命令进行参考。



```bash
man ls
或者
ls --help
ls [-lha]
```

参数介绍:

| **参数** |                  **功能**                  |
| :------: | :----------------------------------------: |
|  **-l**  |       **列出文件和文件夹的详细信息**       |
|  **-h**  | **以人性化的方式显示文件大小(搭配-l使用)** |
|  **-a**  | **显示所有文件及目录(包括隐藏目录和文件)** |

范例:

```bash
ls -l
ls -a
ls -lh
ls -lha
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200223163213504.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70) 

请看红色方框部分,所谓以人性化方式显示文件夹大小就是把每个文件的大小换算成我们熟悉的单位(比如K,M,G)。 



![在这里插入图片描述](https://img-blog.csdnimg.cn/20200223163413713.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70) 

不带任何参数的ls是不能显示隐藏文件(目录)的(linux中以.开头的基本上就是隐藏文件(目录),加上-a参数即可显示隐藏文件(目录)。 另外,一个点（.）在linux中表示当前目录,两个点（. .）在linux中表示上一级目录。（-）可以在两个最近的两个命令间进行切换。

 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200223164628966.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70) 

第一部分的代表的意思： 比如(-rwxrwxrwx)一共有10个字符；

- 第一个字符代表这个文件是目录,文件或者链接文件等。 [d]代表目录,[-]代表文件,[l]代表链接文件。
- 接下来的字符,以三个为一组。 第一组为文件拥有者的权限; 第二组为加入此用户组的用户(账号)的权限; 第三组为其它用户的权限。 [r]代表可读权限，[w]代表可写权限，[x]代表可执行权限。

第二部分代表文件的链接数(硬链接数)

- 就是有多少条路径可以进入到达此文件

第三部分是文件的拥有者的名字(账号)

- linux是多用户用任务的操作系统

第四部分是文件所属组的名字

- linux下文件对文件分组

**Linux下一切皆文件！**

每天一个linux终端命令,积少成多,希望大家越来越优秀!

**才疏学浅，望雅正！**