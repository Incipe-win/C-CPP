---
title: Visual Studio Code配置CC++环境
categories: 
- 软件使用
tags: 
- 博客
---
首先先下载VScode：[VScode](https://code.visualstudio.com/download)
选择适合自己系统的版本。

# 1.安装插件：
快捷键  Ctrl + Shift + X
搜索C/C++，Code Runner

# 2.配置MinGW/Mingw-w64环境变量：
没有安装mingw-w64的可以看看我这个文章 [链接](https://mp.csdn.net/mdeditor/99820556#)
也可以按如下步骤进行：
找到codeblocks的安装位置（前提是安装了该软件）
没装的可以去 http://www.codeblocks.org/downloads/26 安装
点进去文件夹有个MInGw，把里面的bin文件夹路径拷贝下来，
然后配置环境变量。
请参考：[https://mp.csdn.net/mdeditor/99820556#](https://mp.csdn.net/mdeditor/99820556#)

# 3.安装clang：
最新版地址：[http://releases.llvm.org/download.html#8.0.1](http://releases.llvm.org/download.html#8.0.1)
安装不了的可以用网盘下载：
链接：https://pan.baidu.com/s/1NTxwc0lEvkFuaFA95Cn7Aw 
提取码：bmzf 

# 4.安装Visual Studio 
官网：[https://visualstudio.microsoft.com/zh-hans/vs/?rr=https%3A%2F%2Fwww.google.com%2F](https://visualstudio.microsoft.com/zh-hans/vs/?rr=https://www.google.com/)
# 5.创建和设置语言开发工作区：
创建一个代码工作区。
**工作区所在路径仅由字母、数字、下划线组成，不要包含其他的符号**
**绝对不能有中文，中文路径调试时会报错的。**

# 6.编写第一个程序：

```
#include<bits/stdc++.h>
int main()
{
    std::cout<<"Hello World!"<<std::endl;
    std::cin.get();
    return 0;
}

```

# 7.配置

配置调试前执行的任务 task.json和launch.json，c_cpp_properties.json
点击右上角的三角形，运行代码，会自动创建task.json和launch.json的。
task.json如下：

```
{
    "version": "2.0.0",
    "command": "g++",
    "args": [
        "-g",
        //"-std=c++17",
        //"-lstdc++fs",
        "${file}",
        "-o",
        "${file}.exe"
    ], // gcc编译命令参数
    "problemMatcher": {
        "owner": "cpp",
        "fileLocation": [
            "relative",
            "${workspaceRoot}"
        ],
        "pattern": {
            "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
            "file": 1,
            "line": 2,
            "column": 3,
            "severity": 4,
            "message": 5
        }
    }
}
```
launch.json如下：

```
{
    "version": "0.2.0",
    "configurations": [{
        "name": "C++ Launch (GDB)", // 配置名称，将会在启动配置的下拉菜单中显示
        "type": "cppdbg", // 配置类型，这里只能为cppdbg
        "request": "launch", // 请求配置类型，可以为launch（启动）或attach（附加）
        "targetArchitecture": "x86", // 生成目标架构，一般为x86或x64，可以为x86, arm, arm64, mips, x64, amd64, x86_64
        "program": "${file}.exe", // 将要进行调试的程序的路径
        "miDebuggerPath": "D:\\mingw64\\bin\\gdb.exe", // miDebugger的路径，注意这里要与MinGw的路径对应
        "args": [], // 程序调试时传递给程序的命令行参数，一般设为空即可
        "stopAtEntry": false, // 设为true时程序将暂停在程序入口处，一般设置为false
        "cwd": "${workspaceRoot}", // 调试程序时的工作目录，一般为${workspaceRoot}即代码所在目录
        "externalConsole": true, // 调试时是否显示控制台窗口，一般设置为true显示控制台
        "preLaunchTask": "g++" // 调试会话开始前执行的任务，一般为编译程序，c++为g++, c为gcc
    }]
}
```
c_cpp_properties.json：

```
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "compilerPath": "C:\\MinGW\\bin\\gcc.exe",//bin文件夹里面gcc.exe的路径
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "clang-x64"
        }
    ],
    "version": 4
}
```

接下来就可以愉快的用vscode敲代码了，毕竟有强大的微软爸爸支持。微软代码补全特别强大。

另外，有几点补充，codeblocks好像是没有gdb.exe的·，只有个gdb32.exe
可以来网盘下载：
链接：https://pan.baidu.com/s/1iiqxn_sOHkhONzVgPRtfRw 
提取码：8klr 
也可以去：[http://ftp.gnu.org/gnu/gdb/](http://ftp.gnu.org/gnu/gdb/)

Vscode功能很多，留待大家慢慢研究！