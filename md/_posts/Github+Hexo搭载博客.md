---
title: Github+Hexo搭载博客
categories: 
- 软件使用
tags: 
- 博客
---
*很久就想搞个自己的博客了，就从Github Pages练练手吧！*

## 1. 创建Github账户

![](F:/study/blog/source/_posts/images/2020-03-13_194655.png)

![](F:/study/blog/source/_posts/images/2020-03-13_194952.png)



接下来，直接通过**username.github.io**就可以打开Github Pages了！

## 2. 安装Git

这个就是一个软件的安装，不多讲了。

***注：如果不需要用Hexo搭载静态博客框架的，直接在github上操作就好了！***

在settings里面可以更改主题(是仓库里面的设置)

![](F:/study/blog/source/_posts/images/2020-03-13_195705.png)

![](F:/study/blog/source/_posts/images/2020-03-13_195835.png)

点击②修改主题，接着点提交就好了，请注意①处的地址是你所期望的

*ps:有可能出现 https://username.github.io/username.github.io 这样的url*

Github还可以绑定自己购买的域名！

配置*Github*的教程可以参考[传送门](https://blog.csdn.net/qq_43826212/article/details/100023631)

接下来用Hexo搭载静态博客框架！

## 3. 安装Hexo

### 什么是Hexo

Hexo是一款基于Node.js的静态博客框架。 Hexo 使用 [Markdown](https://link.zhihu.com/?target=http%3A//daringfireball.net/projects/markdown/)（或其他渲染引擎）解析文章，在几秒内，即可利用靓丽的主题生成静态网页[^1]

安装Hexo之前，我们需要安装Node.js。Git上文已经安装好了。

### 安装node.js

[官网传送门](https://nodejs.org/en/download/)

安装好后cmd输入**node -v**会出现node.js的版本号

**npm -v**会出现npm版本号

### 安装Hexo

在计算机本地创建一个文件夹，专门用来保存博客。

比如在F盘创建一个study/blog

右键该文件夹，输入

````nodejs
npm install hexo-cli -g
````

有WARN没事的。

````cmd
$ npm install hexo-cli -g
C:\Users\theigrams\AppData\Roaming\npm\hexo -> C:\Users\theigrams\AppData\Roaming\npm\node_modules\hexo-cli\bin\hexo
npm WARN optional SKIPPING OPTIONAL DEPENDENCY: fsevents@1.2.9 (node_modules\hexo-cli\node_modules\fsevents):
npm WARN notsup SKIPPING OPTIONAL DEPENDENCY: Unsupported platform for fsevents@1.2.9: wanted {"os":"darwin","arch":"any"} (current: {"os":"win32","arch":"x64"})

+ hexo-cli@2.0.0
updated 1 package in 25.401s
````

这样子应该是安装成功了，不放心用

```node.js
npm install hexo --save
```

再来一次继续安装！

最后输入

````cmd
hexo -v
````

![](F:/study/blog/source/_posts/images/2020-03-13_201451.png)

有如下信息就说明安装成功！

继续输入

````cmd
hexo init
````

会在blog文件夹下生成配置信息。

接着输入**npm install**安装必备组件。

如果报错:

````cmd
npm WARN deprecated core-js@1.2.7: core-js@<2.6.8 is no longer maintained. Please, upgrade to core-js@3 or at least to actual version of core-js@2.
npm ERR! Unexpected end of JSON input while parsing near '...":{"accepts":"~1.0.7"'

npm ERR! A complete log of this run can be found in:
npm ERR!     C:\Users\theigrams\AppData\Roaming\npm-cache\_logs\2019-06-08T12_56_37_486Z-debug.log
````

输入以下指令清除缓存

````cmd
npm cache clean --force
````

再输入**npm install**，有WARN没关系的。

````cmd
npm WARN deprecated core-js@1.2.7: core-js@<2.6.8 is no longer maintained. Please, upgrade to core-js@3 or at least to actual version of core-js@2.
npm notice created a lockfile as package-lock.json. You should commit this file.
npm WARN optional SKIPPING OPTIONAL DEPENDENCY: fsevents@1.2.9 (node_modules\fsevents):
npm WARN notsup SKIPPING OPTIONAL DEPENDENCY: Unsupported platform for fsevents@1.2.9: wanted {"os":"darwin","arch":"any"} (current: {"os":"win32","arch":"x64"})

added 420 packages from 506 contributors and audited 4697 packages in 58.891s
found 2 low severity vulnerabilities
  run `npm audit fix` to fix them, or `npm audit` for details
````

执行**hexo s**后

打开链接[http://localhost:4000](https://link.zhihu.com/?target=http%3A//localhost%3A4000/)，能看到网页就成功了！

Github+Hexo静态博客框架搭建好了，接下来就进行博客初始配置了！

## 4. 博客初始配置

#### 配置Deployment

首先要明确两个概念
>在 Hexo 中有两份主要的配置文件，其名称都是 `_config.yml`。 其中，一份位于站点根目录`study\blog`下，主要包含 Hexo 本身的配置；另一份位于主题目录`study\blog\themes\landscape`下，这份配置由主题作者提供，主要用于配置主题相关的选项。
>为了描述方便，在以下说明中，将前者称为 **站点配置文件**， 后者称为 **主题配置文件**。

打开**站点配置文件_config.yml**

定位最后一行，改为如下配置：

````config
deploy:
  type: git
  repo: 你的仓库地址
  branch: master
````

![](F:/study/blog/source/_posts/images/2020-03-13_204815.png)

完成后保存，右键blog文件，选择**Git Bush Here**

执行执行以下指令来安装所需的插件：

````
npm install hexo-deployer-git --save
````

有警告没关系！

输入**hexo d**

打开**username.github.io**访问你的个人博客！

#### 写文章

在Git窗口用命令：

````cmd
hexo new post "article title"
````

或者直接在F:\study\blog\source\_posts(这个就是本地博客的路径)建立.md文件即可。

推荐几个markdown好用的编辑器

[mdnice](https://mdnice.com/)

[typora](https://typora.io/)

#### 网站的渲染和发布

修改完**站点**配置文件`_config.yml`或增添新文章后，在终端中依次执行如下代码:

- `hexo clean` 清理缓存
- `hexo generate` 进行渲染 简写 `hexo g`
- `hexo server` 部署到本地(调试使用) 简写 `hexo s`。然后浏览器输入 `http://localhost:4000` 就可以看到你博客的效果啦，不过这是本地调试用，其他人是看不到的。(调试完毕后记得 `control + C` 关闭本地端口，不然下次就进不去啦)
- 调试完毕后使用 `hexo deploy` 简写为 `hexo d`来部署到git服务器。

#### 个性化修改

在站点配置文件修改即可！

![](F:\study\blog\source\_posts\images\2020-03-13_205915.png)

#### 更改主题

主题很多种，笔者用的是[ hexo-theme-next](https://github.com/theme-next/hexo-theme-next)

进入官网[安装说明](https://github.com/theme-next/hexo-theme-next/blob/master/docs/INSTALLATION.md)

进行安装即可。

然后将**站点**配置文件`_config.yml`中的`theme: landscape`修改为`theme: next`

再运行以下指令：

```bash
hexo clean
hexo g
hexo s
hexo d
```

即可看到新主题。

如果报错

````bash
Error: UNKNOWN: unknown error, stat 'F:\study\blog\themes\next\languages\default.yml'
````

根据提示把default.yml删除即可解决问题

最后，祝大家学习愉快！



**才疏学浅，望雅正！**

[^1]: [参考文章](https://zhuanlan.zhihu.com/p/68625591)

