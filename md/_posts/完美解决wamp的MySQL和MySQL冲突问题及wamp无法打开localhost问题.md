---
title: 完美解决wamp的MySQL和MySQL冲突问题及wamp无法打开localhost问题
categories: 
- 软件使用
tags: 
- 博客
---
当我们使用wamp时，如果系统之前已经安装了MySQL，会发现wamp的MySQL和原来的MySQL只有一个可以使用，原因就是因为端口冲突。可能还会经常遇到的一个问题，就是安装了wamp后无法打开localhost，原因也是因为端口冲突。下面这篇文章将带大家解决这两个问题。
# 解决MySQL端口冲突问题
我们需要修改则两个文件。
路径：
>D:\wamp64\bin\mysql\mysql5.7.26\my.ini
>D:\wamp64\apps\phpmyadmin4.8.5\config.inc.php

## 打开my.ini
````cpp
[client]
;password = your_password
port = 8081
socket = /tmp/mysql.sock

; Here follows entries for some specific programs

; The MySQL server
[wampmysqld64]
;skip-grant-tables
default_authentication_plugin=mysql_native_password
port = 8081
socket = /tmp/mysql.sock
key_buffer_size = 256M
max_allowed_packet = 1M
...
及最后一部分
[mysqld]
default_authentication_plugin=mysql_native_password
port = 8081
````
把以上的port = 后的端口号改为自己想要的即可(我这里改为了8081，原先是3306的)。
## 打开config.inc.php
````cpp
if($mariaFirst) $i++;
	$cfg['Servers'][$i]['verbose'] = 'MySQL';
	$cfg['Servers'][$i]['host'] = 'localhost';
	$cfg['Servers'][$i]['port'] = '8081';			//这里改为你的端口号
	$cfg['Servers'][$i]['extension'] = 'mysqli';
	$cfg['Servers'][$i]['auth_type'] = 'cookie';
	$cfg['Servers'][$i]['user'] = 'root';
	$cfg['Servers'][$i]['password'] = '这里填写你的MySQL密码';
````
保存退出，重启就好了。
**（控制台设置wamp的MySQL密码时，如果
输入
【update user set password=PASSWORD('root') where user='root';】
报错
【ERROR 1054 (42S22): Unknown column 'password' in 'field list'】
命令改为
update mysql.user set authentication_string=password('root') where user='root'；即可解决问题
）**
# 解决localhost无法打开问题
找到几个文件
>D:\wamp64\bin\apache\apache2.4.39\conf\httpd.conf
>D:\wamp64\wampmanager.tpl

## 打开httpd.conf
Ctrl + F 搜索80
修改这几个部分
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191125124240273.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191125124320776.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
改为自己想要的即可(我这里改成了8080)
## 打开wampmanager.tpl
Ctrl + F 搜索80，修改这几处地方即可

![在这里插入图片描述](https://img-blog.csdnimg.cn/20191125124703709.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191125124737763.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
改成跟httpd.conf中一样的端口即可！
保存重启即可！
**注意：此时访问localhost需要加上端口号，因为以前默认的时80，现在改成了8080，及localhost:端口号**
如果wamp的图标显示绿色，那么说明wamp的所有服务全部开启了。如果是红色或者橙色，说明有服务没开启！
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191125125346871.png)
才疏学浅，望雅正！