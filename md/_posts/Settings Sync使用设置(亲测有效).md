---
title: Settings Sync使用设置(亲测有效)mingw-w64安装
categories: 
- 软件使用
tags: 
- 博客
---
***会当凌绝顶，一览众山小***



网上看了很多关于Sync的教程，感觉好像已经过时了，可读性不高，按照步骤也设置不好，结合自己的理解，和对他人的参考，`在这里插入代码片`写了个简单实用的教程！

## 1.首先安装Seetings Sync
安装完毕后，打开Sync设置
*方法：F1->Sync:Advanced Options->Sync:打开设置*
我们只要配置这两个地方就好了!
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191222232059953.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
## 2.打开Github
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191222232258999.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191222232504633.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191222232639170.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
点Generate token(生成令牌,在最下方)
然后你会得到一串令牌,复制下来到Sync的Global Settings里面!
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191222233009585.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
创建gists
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191222233159557.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
好了之后，点击去创建的gists
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191222233536475.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
然后在地址栏最后一串字符就是Gists ID
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191222234059997.png)
复制填到Sync的Gists ID里面即可！
然后，Alt + Shift + U上传
Alt + Shift + D下载即可！
不仅上传插件，所有的配置文件也会上传，以后换电脑只要下载这个插件，填好令牌和ID，用Alt + Shift + D就可以使用原来自己配好了的Vscode了，大大提升了效率！

**才疏学浅，望雅正！**