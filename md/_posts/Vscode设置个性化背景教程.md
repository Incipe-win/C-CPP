---
title: Vscode设置个性化背景教程
categories: 
- 软件使用
tags: 
- 博客
---
Vscode都配置好了，接下来设置一个有趣的个性化背景。
如果没有安装好C++编译环境可以参考：[写的很好](https://blog.csdn.net/yanwennian/article/details/103516385?utm_source=app)

1.搜索插件background
安装好了以后会出现插件破损的提示，别理，设置为不再提醒。

2.配置

```
"background.enabled": true,
    "background.useDefault": false,
    //是否使用默认图片
    "background.customImages": [
        "file://D:/2345Downloads/png/Live.png",
        "file://D:/2345Downloads/png/Live2D1.png",
        "file://D:/2345Downloads/png/Live2D2.png"
        //"file://D:/2345Downloads/png/1.jpg",//图片路径
    ],
    "background.style": {
        "content": "''",
        "pointer-events": "none",
        "position": "absolute",
        "z-index": "99999",
        "width": "100%",
        "height": "100%",
        "background-position": "100% 100%",
        "background-repeat": "no-repeat",
        "opacity": 0.35
    }
```


把上面的加入到settings的配置文件当中就好了。
点击file->preferences->settinigs
然后就好了。上张图：

![在这里插入图片描述](https://img-blog.csdnimg.cn/2019082114544836.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)

补充：插件够用就好，不要装太多了。
**才疏学浅，望雅正！**