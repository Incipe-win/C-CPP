---
title: 嵌入式学习笔记(2)
categories: 
- IOT
tags: 
- 博客
---

## ARM体系

ARM：Advanced RISC Machine

### ARM命名规则

|          ARMv           |      n       | variants |   x (variants)    |
| :---------------------: | :----------: | :------: | :---------------: |
| 固定字符，即ARM Version | 指令集版本号 |   变种   | 排除x后指定的变种 |

常见的variants有以下几种：

+ T -- Thumb指令集
+ M -- 长乘法指令
+ E  -- 增强型DSP指令
+ J  -- Java加速器Jazelle
+ D  -- 支持片上Debug
+ I   -- 嵌入式ICE，支持片上断点和调试
+ z  -- cache

比如：**ARM7TMDI**表示ARM指令集版本为7，支持**TMDI**变种

在 **ARMv7** 以后时期，统一用 Cortex 作为主名。

![image-20200318200830713](https://i.loli.net/2020/03/18/6b8xJurhjlPngAz.png)

### ARM公司

1. **ARM**公司于1990年11月在英国剑桥成立，前身为**Acorn**计算机公司。
2. **ARM**公司是全球领先的16/32位嵌入式**RISC**微处理器解决方案供应商。
3. **ARM**公司是知识产权(**IP**)公司，本身不生产芯片，靠转让设计许可，由合作伙伴公司来生产各具特色的芯片。

目前，全世界有几十家著名的半导体公司都使用**ARM**公司的授权，其中包括**MOTOROLA**、**IBM**、**Intel**、**LG**、**SONY**、**NEC**、**ATMEL**等，从而保证了大量的开发工具和丰富的第三方资源，它们共同保证了基于**ARM**处理器核的设计可以很快投入市场。

**ARM**公司已成为移动通信、手持设备、多媒体数字消费嵌入式解决方案的**RISC**标准。

### ARM Cortex系列

|          Cortex-A           |          Cortex-R          |                Cortex-M                 |                   Machine Learing                   |        SecureCore        |
| :-------------------------: | :------------------------: | :-------------------------------------: | :-------------------------------------------------: | :----------------------: |
| Highest Performance(高性能) | Real-Time Processing(实时) | Lowest Power, Lower Cost(低功率,低成本) | Efficiency Uplift for All Devices(提高所有设备效率) | Tamper Resistant(防篡改) |

### ARM处理器运行模式

#### 内存字节顺序

+ 大端模式(Big Endian)
+ 小端模式(Little Endian)

![image-20200318194956268](https://i.loli.net/2020/03/18/KV8RhDyjbAI2GQ5.png)

我们用ARM的一般是32-bit体系结构

+ 1 Byte = 8 bits
+ 半个字(Halfword) 是16bits (2Byte)
+ 一个字(Word)是32bits(4Byte)
+ ARM指令集32位，Thumb指令集16位，Thumb集为ARM指令集的子集

|         mode         | 特权模式(Y/N) | 异常模式(Y/N) |             description              | 二进制表示 |
| :------------------: | :-----------: | :-----------: | :----------------------------------: | :--------: |
|    User(用户模式)    |               |               |      大多数任务运行的非特权模式      |   10000    |
|   System(系统模式)   |       Y       |               |   使用与用户相同的寄存器的特权模式   |   10001    |
|  FIQ(快速中断模式)   |       Y       |       Y       | 当一个高优先级(快速)中断被引起时输入 |   10010    |
|  IRQ(外部中断模式)   |       Y       |       Y       | 当一个低优先级(普通)中断被引起时输入 |   10011    |
| Supervisor(管理模式) |       Y       |       Y       |    在复位和执行软件中断指令时输入    |   10111    |
|   Abort(中止模式)    |       Y       |       Y       |         用于处理内存访问冲突         |   11011    |
|  Undef(未定义模式)   |       Y       |       Y       |         用于处理未定义的指令         |   11111    |

总的来讲可以分为两大类：

+ 特权模式(其余6个模式)和非特权模式(User)

针对特权模式(除User模式以外的模式)：

+ 系统模式(System)和异常模式(其余5种)

### ARM7TDMI-S core的逻辑结构

+ 32bits
+ Load/Store
+ 31个通用寄存器组(**general purpose register** )，6个状态寄存器(**status register**)
  + R0~R12通用寄存器
  + R13堆栈指针(Stack Pointer)
  + R14链接寄存器(Link Register)
  + R15程序指针(Program Counter)
  + CPSR当前程序状态寄存器(Current Program Status Register)
  + SPSR保存程序状态寄存器(Saved Program Statuc Register)

ARM状态下的寄存器组织：

![ARM状态下的寄存器组织](https://i.loli.net/2020/03/18/GTu6Frz5mVIojck.png)

未分组寄存器R0~R7

+ 在所有的运行模式下，未分组寄存器都指向同一个物理寄存器，他们未被系统用作特殊的用途，因此，在中断或异常处理进行运行模式转换时，由于不同的处理器运行模式均使用相同的物理寄存器，可能会造成寄存器中数据的破坏，这一点在进行程序设计时应引起注意。

分组寄存器R8~R12

+ 每次所访问的物理寄存器与处理器当前的运行模式有关
+ **R8～R12**：每个寄存器对应两个不同的物理寄存器
  + 当使用**fiq**模式时，访问寄存器**R8_fiq～R12_fiq**
  + 当使用除**fiq**模式以外的其他模式时，访问寄存器**R8_usr～R12_usr**

### ARM异常处理

#### R14(LInk Register链接寄存器)

+ R14保存的是程序的地址(程序的返回地址)

  ````armasm
  # 调用子程序(异常)
  STMFD SP!,{<Regs>,LR}
  # 子程序返回(异常返回)
  LDMFD SP!,{<Regs>,PC}
  ````

当前程序状态寄存器(Current Program Status Register)

![当前程序状态寄存器](https://i.loli.net/2020/03/18/ypGErWXQstfHBSi.png)

一般用SPSR来恢复CPSR！

#### 异常(Exception)

+ 当程序的正常流程必须临时停止时，就会出现异常，例如为来自外设的中断提供服务。在尝试处理异常之前，ARM7TDMI-S保留当前处理器状态，以便在处理程序例程完成后可以恢复原始程序。
+ 优先级(Priority)
  1. Reset(highest priority) -> 重置
  2. Data Abort -> 数据预取中止
  3. FIQ
  4. IRQ
  5. Prefetch Abort -> 指令预取中止
  6. Undefined instruction -> 未定义指令
  7. SWI(lowest priority) -> 软件中断(software interrupt)

#### 进入异常流程

1. Preserves the address of the next instruction in the appropriate LR.(在适当的LR中保留下一条指令的地址)
2. Copies the CPSR into the appropriate SPSR.(将CPSR复制到适当的SPSR中)
3. Forces the CPSR mode bits to a value which depends on the exception.(将CPSR模式位设置为当前异常模式位)
4. Forces the PC to fetch the next instruction from the relevant exceptions.(使PC处理相应的异常)

中断向量表(Vector Table)

![中断向量表](https://i.loli.net/2020/03/18/b98WngIeHRkq6lT.png)

#### 异常返回

1. PC  = LR - offset
2. SPSR -> CPSR
3. Clear the interrupt disable flags that were set on entry(清除在中断时时设置的中断禁用标志)

![image-20200318213758689](https://i.loli.net/2020/03/18/kuF5jrey2t4Bown.png)

**才疏学浅，望雅正！**