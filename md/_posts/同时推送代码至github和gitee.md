---
title: 同时推送代码至github和gitee
categories: 
- 软件使用
tags: 
- 博客
---
1.注册github和gitee账号
这就不说了，很简单，然后创建仓库。github仓库的英文名是：Repository 。


2.下载git
git是分布式版本控制系统，官网下载地址：[https://git-scm.com/downloads](https://git-scm.com/downloads)
选择版本下载安装，安装的时候没特别需求一路next就好了。

3.获取公钥
鼠标右键，选择Git Bash here，输入`ssh-keygen -t rsa -C “邮箱”`
如图：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190822203737221.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
我的已经安装好了，遇到停顿一路回车就好了。
产生的公钥在C:/用户(user)/admin(每个电脑不一样的相当于电脑的username)/.ssh/id_rsa.pub
复制下来.。
或者直接用`cat ~/.ssh/id_rsa.pub`查看。
可用`ssh -T git@github.com`查看是否成功生成公钥。

4.上传公钥
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190822204532424.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
点击右上角的头像，点击settings
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190822204712208.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
点击SSH and GPG keys
添加SSH keys，不需要添加GPG keys
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190822205007546.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
如图即可。
gitee一样的步骤。

5.绑定用户名跟邮箱
在git界面输入：

    git config --global user.name "github的用户名"
    
    git config --global user.email "绑定github的邮箱"

到了这一步就差不多了。
新建一个文件夹，专门用来传代码。
右键该文件夹。
选择Git Bash here
初始化，同步该文件夹

```
git init

git remote add origin 仓库地址（如下图）

git pull origin master
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190822210452256.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
然后现在就可以上传代码到github上面了。

```
git add . 

git commit -m "理由"

git push origin master
```
要修改，只需要在本地进行修改，再同步即可，当然也有其他方法。

6.同时推送代码至github和gitee
找到刚刚新建的文件夹，打开显示隐藏项目，会看到`.git`的文件夹
右键`.git`文件夹，Git Bash here
输入`vim config`
接下来你进入的是vim编辑器，号称编辑器之神。
这里不讲怎么使用。点击`i/a/o`j进入插入模式
增加如下内容

```
[remote "gitee"]
	url = 你的gitee项目地址
	fetch = +refs/heads/*:refs/remotes/gitee/*
[branch "master"]
	remote = gitee
	merge = fefs/heads/master
```
可以看到前面已经有内容了，那是上传到github的配置。
然后按ESC键，多按几次没事的，按`Shift+:wq`
vim编辑器会在最下面一行显示如下内容，按Enter就可以了
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190822211814756.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzODI2MjEy,size_16,color_FFFFFF,t_70)
最后就可以上传代码了。

```
git add .
git commit -m "理由"
```
上传至github

```
git origin origin master
```
上传至gitee

```
git push gitee master
```
然后就可以享受代码托管，开源的乐趣了。