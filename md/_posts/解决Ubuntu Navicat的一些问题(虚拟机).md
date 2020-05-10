---
title: 解决Ubuntu Navicat的一些问题(虚拟机)
categories: 
- Linux
tags: 
- 博客
---
先安装好MySQL
````shell
sudo apt-get install mysql-server

sudo apt-get install mysql-client

sudo apt-get install libmysqlclient-dev


检查是否成功：sudo ps -aux | grep mysql
如果看到有mysql 则表示安装成功。
````
配置MySQL
````shell
sudo mysql_secure_installation
````
设置好密码后会出现一些安全设置:(我的输入是nyyy)[^1]
验证MySQL是否正在运行

````bash
systemctl status mysql.service
````
有running显示即说明MySQL在运行!
注：登录mysql时一定要加**sudo**
## 一.远程登录问题
## 1.修改配置文件
终端输入
````shell
netstat -an | grep 3306
````
如果3306前面是127.0.0.1,就要求我们去修改配置文件了。
````bash
vim /etc/mysql/mysql.conf.d/mysqld.cnf
````
把bind-address = 127.0.0.1改成0.0.0.0，没有bind-address就直接加上
>bind-address=0.0.0.0
## 2.允许所有用户远程登录
+ 登录mysql数据库
	````bash
	sudo mysql -u[用户名] -p[密码]
	````
	一定要加**sudo**，不加登不进去的。
+ 修改 root 的 host 属性为 %
	````bash
	use mysql;
	select host, user from user;
  	update user set host = '%' where user = 'root'; 
  ````
### 3. 出现1698- access denied for user 'root'@'ip'
原因可能是因为MySQL默认使用了UNIX auth_socket plugin插件。
简单来说这意味着当db_users使用数据库时，将会通过系统用户认证表进行认证。
+ 在服务器的mysql上执行
````SQL
  SELECT User, Host, plugin FROM mysql.user;
  
  +------------------+-----------------------+
  | User             | plugin                |
  +------------------+-----------------------+
  | root             | auth_socket           |
  | mysql.sys        | mysql_native_password |
  | debian-sys-maint | mysql_native_password |
  +------------------+-----------------------+
````
root用户在使用 auth_socket 插件。
解决方法：
+ 可以设置你的root用户使用 mysql_native_password 插件
````SQL
  USE mysql;
  UPDATE user SET plugin='mysql_native_password' WHERE User='root';
  FLUSH PRIVILEGES;
  exit;
````

或者
+ 用你的操作系统用户名代替YOUR_SYSTEM_USER
````SQL
  USE mysql;
  CREATE USER 'YOUR_SYSTEM_USER'@'localhost' IDENTIFIED BY '';
  GRANT ALL PRIVILEGES ON *.* TO 'YOUR_SYSTEM_USER'@'localhost';
  UPDATE user SET plugin='auth_socket' WHERE User='YOUR_SYSTEM_USER';
  FLUSH PRIVILEGES;
  exit;
````
选一种就好了。
重启数据库[^2]

````bash
sudo mysql restart
````
## 二.字体问题
找到Navicat文件
````shell
sudo vim start_navicat
````
>把export LANG="en_US.UTF-8" 将这句话改为 export LANG="zh_CN.UTF-8"

这还不能解决所有的乱码问题。
进去Navicat，点开工具：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200301214436463.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
把这几处的字体改为[Noto Sans mono CJK SC Regular[^3]
基本上字体问题都已解决!

## 三.破解问题

到~目录下，使用
````shell
ls -lh
````
删除.navicat文件[^4]
注意：**此种破解方式的缺点在于 删除日志文件后, navicat各种设置(比如字符设置)会被清空**

**才疏学浅，望雅正！**

[^1]:[参考](https://wangxin1248.github.io/linux/2018/07/ubuntu18.04-install-mysqlserver.html)
[^2]:[参考](https://juejin.im/post/5c34521d518825251077b5d2)
[^3]:[直接复制字体到Navicat里面粘贴](https://www.cnblogs.com/tanrong/p/10173109.html)
[^4]:[或者删除此文件夹下的 system.reg    user.reg   userdef.reg 文件](https://www.cnblogs.com/tanrong/p/10173109.html)