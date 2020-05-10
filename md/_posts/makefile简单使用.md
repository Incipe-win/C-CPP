## 一. 题外话

### 1.1 c/cc编译流程

以 **main.cpp** 为例：

![编译过程](https://imgkr.cn-bj.ufileos.com/c2d179b7-7ea5-4197-8bb8-c1d0196f27e8.png)

### 1.2 gcc编译参数( 部分)

除了前面的 `-E -S -c` 以外

+ **-o** 指定输出的文件名；
+ **-Wall** 启用所有警告；
+ **-w** 不产生任何警告；
+ **-g** 生成调试信息；
+ **-I** 指定头文件路径；
+ **-l** 链接共享库，小写的 **l** ；
+ **-L** 指定库文件路径，大写的 **L** ；
+ **-D** 定义编译时的宏；
+ **-Werror** 将所有的警告转换成错误信息；
+ **-ansi** 只支持 ANSI 标准的 C 语法；
+ **-fexec-charset=GBK** **bin** 文件为 **GBK** 编码。

所有的参数可见 [Option Summary](https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html)

### 1.3 静态库和动态库

**windows** 下后缀名 **.lib** (静态库)， **.dll** (动态库)

**linux** 下后缀名 **.a** (静态库)， **.so** (动态库)

只介绍 **linux** 下的库文件制作

#### 1.3.1 静态库制作

##### 命名

**"lib[your_library_name].a"** ，中间是静态库名字。

##### 创建

+ 先编译成目标文件
  + **g++ -c main.cpp**
+ 通过 **ar** 工具将目标文件打包成 **.a** 静态库文件
  + **ar -crv libstaticmain.a main.o **

用 **nm** 可查看静态库内容。

#### 1.3.2 动态库制作

##### 命名

**"lib[your_library_name].so"** ，中间是静态库名字。

##### 创建

+ 创建与地址无关的编译程序
  + **g++ -fPIC -c main.c**
+ 打包为动态库(共享库)
  + **gcc -shared -o libdymain.so main.o**

静态库使用和动态库是一样的，但是执行的时候找不到动态库。

解决办法：

+ 拷贝到系统的库路径下，不推荐；
+ 修改 **LD_LIBRARY_PATH** 环境变量，将库所在的路径添加到环境变量中；
+ 添加库路径到 **/etc/ld.so.conf** ，运行 **sudo ldconfig -v** ( **-v** 可加可不加 )，该命令会重建 **/etc/ld.so.cache** 文件。

详细解释可以参考 [C++静态库与动态库](https://www.cnblogs.com/skynet/p/3372855.html)

## 二. makefile格式

> ```bash
> <target> : <prerequisites> 
> [tab]  <commands>
> ```

**target** 目标，  **prerequisites**  条件， **commands** 命令 。

目标不能省略，条件和命令都可以省略。

### 2.1 目标

目标通常是文件名，表明 **make** 要构建的对象。目标可以有多个，中间用空格分开。

为了防止目标和文件名冲突，产生了伪目标( **phony target** )

比如：

````bash
clean:
	rm -r *.o
````

如果当前路径下有个叫 **clean** 的文件，那么使用 **make clean** 就无法生效了。

这时添加伪目标即可解决。

````bash
.PHONY : clean
````

伪目标可以有多个，中间用空格隔开。

**make** 没有指定目标，默认执行第一个。

### 2.2 条件

前置条件通常是一组文件名，之间用空格分隔。它指定了"目标"是否重新构建的判断标准：只要有一个前置文件不存在，或者有过更新（前置文件的 **last-modification** 时间戳比目标的时间戳新），"目标"就需要重新构建。

### 2.3 命令

命令（ **commands** ）表示如何更新目标文件，由一行或多行的Shell命令组成。它是构建"目标"的具体指令，它的运行结果通常就是生成目标文件。

## 三. 两种常用的makefile书写方式

### 3.1 编译多文件

````bash
all : app

cc = g++
include = ../Include

.PHONY : clean all

src = $(wildcard *.cc)
obj = $(patsubst %.cc, %.o, $(src))

app : $(obj)
	$(cc) -o app -I $(include) $(obj)

%.o : %.cc
	$(cc) -c $< -I $(include) -o $@

clean:
	rm -f *.o
	rm -f app
````

这里的 **wildcard** 是 **makefile** 的内置函数，找出所有的 **.cc** 文件，赋值给变量 **src** 。

**patsubst** 函数用于模式匹配的替换，它需要 **3** 个参数：第一个是一个需要匹配的式样，第二个表示用什么来替换它，第三个是一个需要被处理的由空格分隔的字列。

 **%.o : %.cc** 用到了 **makefile** 的模式匹配

更多可以参考 [8 Functions for Transforming Text](http://www.gnu.org/software/make/manual/html_node/Functions.html)

**$<** 和 **$@** 是 **makefile** 的自动变量：

+ **$@**
  + $@指代当前目标，就是Make命令当前构建的那个目标。
+ **$<**
  + $< 指代第一个前置条件。
+ **$?**
  + $? 指代比目标更新的所有前置条件，之间以空格分隔。
+ **$^**
  + $^ 指代所有前置条件，之间以空格分隔。
+ **$\***
  + $* 指代匹配符 % 匹配的部分。

更多可以参考 [10.5.3 Automatic Variables](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)

### 3.2 生成多个可执行文件

````bash
all : hello world

cc = g++
include = ../Include

.PHONY : all clean

hello : hello.o
	$(cc) -o hello -I $(include) hello.o

world : world.o
	$(cc) -o world -I $(include) world.o

hello.o : hello.cc
	$(cc) -c hello.cc -I $(include)

world.o : world.cc
	$(cc) -c world.cc -I $(include)

clean :
	rm -f *.o
	rm -f hello world
````

更详细可参考 [Make 命令教程](http://www.ruanyifeng.com/blog/2015/02/make.html)

## 总结

学会 **makefile** 对以后的编程还是有很大帮助的，可以大大提高自己编写代码的效率。

> [Linux 环境下的程序员如果不会使用GNU make来构建和管理自己的工程，应该不能算是一个合格的专业程序员，至少不能称得上是 Unix程序员。](https://baike.baidu.com/item/makefile)

## 诗情画意

> <center>青玉案·版本二</center>
> <center>贺铸</center>
> <center>凌波不过横塘路，但目送，芳尘去。</center>
> <center>锦瑟华年谁与度？月桥花院，锁窗朱户，只有春知处。</center>
> <center>碧云冉冉蘅(héng)皋(gāo)暮，彩笔新题断肠句。</center>
> <center>试问闲情都几许？一川烟草，满城风絮，梅子黄时雨。</center>
>
> <center>青玉案·版本一</center>
> <center>贺铸</center>
> <center>凌波不过横塘路，但目送，芳尘去。</center>
> <center>锦瑟华年谁与度？月台花榭，锁窗朱户，只有春知处。</center>
> <center>碧云冉冉蘅皋暮，彩笔新题断肠句。</center>
> <center>试问闲愁都几许？一川烟草，满城风絮，梅子黄时雨。</center>



