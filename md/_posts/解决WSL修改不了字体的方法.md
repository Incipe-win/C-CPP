---
title: 解决WSL修改不了字体的方法
categories: 
- Linux
tags: 
- 博客
---
win+r
输入`regedit`
找到：

```
计算机\HKEY_CURRENT_USER\Console\C:_Program Files_WindowsApps_CanonicalGroupLimited.UbuntuonWindows_1804.2019.521.0_x64__79rhkp1fndgsc_ubuntu.exe
```
右键新建：`DWORD类型`，名字`CodePage`，确定，右键修改：16进制`0x01b5`
解决问题。