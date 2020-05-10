---
title: 解决笔记本连接wifi提示无法连接这个网络问题
categories: 
- 软件使用
tags: 
- 博客
---
这几天被这个该死的折腾的死去活来，网上找了好多教程，试过之后感觉都没用（其实很多还是有用的，讲的跟自己做的貌似不太一样）小声逼逼QAQ

首先，很大概率上不是电脑硬件坏了。
基本上都是驱动问题。
win10自带的疑难杂症估计也解决不了。
重置电脑也太麻烦了QAQ
另外，可以去更新下驱动，鲁大师就行了。

千万不要**轻易**去用这个命令：`netsh winsock reset`就是重置网络命令。

当然，密码没输入正确，被拉黑了就没什么好讲的了。

在右下角找到wifi图标
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190826174807397.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190826174855881.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190826174932635.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190826175023967.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190826175100988.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190826175205497.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190826175317482.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190826175503163.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
然后可能就可以了。
要是还不可以，就用把驱动卸载，手动重新安装（系统自己会重新安装的，但是不一定有效）。
要是实在是连接不了，就拿去给高手看看吧。