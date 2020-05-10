---
title: 解决centos使用sudo时出现“用户名 is not in the sudoers file. This incident will be reported.”的问题
categories: 
- Linux
tags: 
- 博客
---
***活在自然美景之中，人就懒，懒就善。***



安装好Centos后，想通过终端安装点软件，总是提示用户权限不足，使用**sudo**提升权限的话，就会出现**用户名 is not in the sudoers file. This incident will be reported.** 的提示，这时我们需要在sudoers文件里面把自己的用户名加进去。
1.进入root用户

>su root

2.终端输入
>usermod -G sudo 用户名
>重启

或者按以下步骤：

2.修改文件权限
>chmod u+w /etc/sudoers

3.编辑sudoers文件
>vim /etc/sudoers

4.找到**root ALL=(ALL) ALL**
在下面添加一行
>你的用户名 ALL=(ALL) ALL
>或者
>你的用户名 ALL=NOPASSWD:ALL

5.保存退出
>wq!

接下来就可以使用sudo提升权限了。

**才疏学浅，望雅正！**