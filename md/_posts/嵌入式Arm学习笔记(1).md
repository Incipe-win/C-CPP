---
title: 嵌入式学习笔记(1)
categories: 
- IOT
tags: 
- 博客
---

### 计算机系统(Computer System)

+ 个人计算机(Personal Computer)
+ 服务器(Server)
+ 嵌入式系统(Embedded System)

对比

|                             |   Server    | Personal Computer | Embedded System  |
| :-------------------------: | :---------: | :---------------: | :--------------: |
|   CPU Capability(CPU能力)   |    High     |      Medium       | Low / Vary(变化) |
| Power consumption(能量功耗) |    High     |   Medium / Low    |     Very Low     |
| Application area(应用领域)  | Data Center |     Personal      |       Vary       |
|     Reliability(可靠性)     |    High     |        Low        |     Rigorous     |
|         Cost(费用)          |    High     |        Low        |       Vary       |

### 嵌入式系统(Embedded System)

#### 嵌入式系统定义(Definition)

+ [维基百科]([https://zh.wikipedia.org/wiki/%E5%B5%8C%E5%85%A5%E5%BC%8F%E7%B3%BB%E7%BB%9F](https://zh.wikipedia.org/wiki/嵌入式系统))

+ [百度百科]([https://baike.baidu.com/item/%E5%B5%8C%E5%85%A5%E5%BC%8F%E7%B3%BB%E7%BB%9F](https://baike.baidu.com/item/嵌入式系统))

#### 微控制器 VS 微处理器(Mircocontroller VS Microprocessor)

1. 都有CPU
2. 微控制器除了有CPU，还集成了ROM，RAM，定时器，I/O端口，串口(serial port)

#### 嵌入式系统分类

+ 小规模嵌入式系统(Small-scale)
+ 中规模嵌入式系统(Medium-scale)
+ 复杂的嵌入式系统(Sophisticated)

#### 基本的嵌入式系统组成

+ 微处理器
+ RAM，ROM
+ Input/Output(键盘……)
+ I/O端口
+ 网络单元(Networks)
+ Timers(定时器)

#### 两大结构体系

+ 冯诺依曼结构(Von-Neumann architecture)

![](https://imgkr.cn-bj.ufileos.com/bf3673e0-5b62-4499-b474-24c73f515432.svg)

+ 哈佛结构(Harvard architecture)

![](https://imgkr.cn-bj.ufileos.com/8fcb07b8-98fd-4145-b1a6-4525700fc2aa.svg)

#### 两种指令集
+ [复杂指令集(CISC)]([https://zh.wikipedia.org/wiki/%E5%A4%8D%E6%9D%82%E6%8C%87%E4%BB%A4%E9%9B%86](https://zh.wikipedia.org/wiki/复杂指令集))
+ [精简指令集(RISC)]([https://zh.wikipedia.org/wiki/%E7%B2%BE%E7%AE%80%E6%8C%87%E4%BB%A4%E9%9B%86](https://zh.wikipedia.org/wiki/精简指令集))

性能方程
$$
\frac{time}{program} = \frac{time}{cycle} \times \frac{cycle}{instruction} \times \frac{instructions}{program}
$$

|                              |      CISC       |     RISC     |
| :--------------------------: | :-------------: | :----------: |
|  Instruction set(指令系统)   |      large      |     <100     |
|   Execution time(执行时间)   |      vary       |    short     |
| Instruction Length(指令长度) | 1~15byte  vary  | 4byte  fixed |
|  Addressing mode(寻址模式)   |      many       |     few      |
|   Memory access(访问内存)    | directly access |  load/store  |
|      Pipeline(传递途径)      |    difficult    |     easy     |



**才疏学浅，望雅正！**