---
title: 用Fiddler构造http请求
categories: 
- 软件使用
tags: 
- 博客
---
用Fiddler构造http请求时，发现 $_POST数组中怎么也获取不到值，以为自己操作错了，但也没发现什么问题，后来得知，原来缺少了一个请求头，Fiddler不会为我们自动添加。
````
Content-Type: application/x-www-form-urlencoded
````
下面以bugku的web基础$_POST30为列子进行分析！
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191128111600242.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191128111642839.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
看到是post请求，就想到构造http的post请求取得flag
打开Fiddler
在composer的options勾选Fix Content-Length header
如图：![在这里插入图片描述](https://img-blog.csdnimg.cn/201911281122538.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
在composer的请求头添加一行
````
Content-Type: application/x-www-form-urlencoded
````
添加好请求体，按Execute即可！

**注：要添加的请求体是what=flag等号左右不能有空格，有多个要用&连接，如：what1=flag1&waht2=flag2**
还有另外其他几种格式化数据方式，参见：[传送门](https://www.cnblogs.com/xiaoxi-3-/p/7612254.html)