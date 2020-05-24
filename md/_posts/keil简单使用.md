注：本文适合绝对0基础，如果有一定的基础，可以移步。

### 一. keil简单介绍

**Keil** 提供了包括C[编译器](https://baike.baidu.com/item/编译器/8853067)、宏汇编、链接器、库管理和一个功能强大的仿真调试器等在内的完整开发方案，通过一个[集成开发环境](https://baike.baidu.com/item/集成开发环境/298524)（μVision）将这些部分组合在一起。

更多请戳 [百度百科](https://baike.baidu.com/item/Keil)

### 二. 安装

[Download Products](https://www.keil.com/download/product/)

![keil产品](https://imgkr.cn-bj.ufileos.com/57af1f52-e355-42a6-b6cd-5bfce14aacac.png)

**MDK-Arm(Microcontroller Development Kit)** 

+ **MDK** 的设备数据库中有很多厂商的芯片，是专为微控制器开发的工具，为满足基于 **MCU** 进行嵌入式软件开发的工程师需求而设计，支持 **ARM7，ARM9，Cortex-M4/M3/M1，Cortex-R0/R3/R4** 等 **ARM** 微控制器内核。

**C51**

+ **KEIL** 公司开发的基于 **uVision IDE** ，支持绝大部分8051内核的微控制器开发工具。

**C251**

+ **KEIL** 公司开发的基于 **uVision IDE** ，支持绝大部分基于251核的微控制器的开发工具。

**C166**

+ **KEIL** 公司开发的基于 **uVision IDE** ，支持绝大部分 **XC16x，C16x** 和 **ST10** 系列的微控制器开发工具。

[破解移步](https://www.mr-wu.cn/keil-mdk-uvision-5-crack/)

### 三. 使用教程

#### 1. 建立文件

在你找的找的到的任何地方建立一个新的文件夹，专门用来保存 **keil** 工程文件。比如 **D://MCU/** 

#### 2. 建立工程文件

在 **MCU** 文件里建立再建立一个文件夹，作为 **keil** 工程文件，比如 **D://MCU/experiment1/** 

#### 3. 建立工程

打开桌面的 **keil uVision** 

![](https://imgkr.cn-bj.ufileos.com/b179aa98-23ab-40f0-9ef0-30c73bfccb81.png)

4. 点击工具栏的 **Project** ，选择 **New uVision Project** 

![](https://imgkr.cn-bj.ufileos.com/261b2a09-c4a6-4d6a-8246-7cc46b584159.png)

定位到刚刚建立的文件夹下面 **D://MCU/experiment** 

![](https://imgkr.cn-bj.ufileos.com/e4c294eb-7574-4da2-aebf-c2f5bf06b896.png)

①是当前路径，我们在②处填上我们要建立的 **keil** 工程名字： **experiment1**，点击③保存。

![](https://imgkr.cn-bj.ufileos.com/8f7ea78e-1052-45c2-8e34-691017023f79.png)

选择 **Atmel** ，点击前面的 **+** 号。

![](https://imgkr.cn-bj.ufileos.com/341976cb-3aa3-4803-84b3-3002c56bd33d.png)

找到 **AT89C51** 点击②， **OK**。

有可能会出来一个弹窗，点否就行了。

#### 4. 建立源文件

找到刚刚建立的 **D://MCU/experiment** 

右键，建立文本文档，双击改名字，记得打开文件后缀名。

![](https://imgkr.cn-bj.ufileos.com/dd735005-111b-49dd-bb46-a5f39e35afb5.png)

![](https://imgkr.cn-bj.ufileos.com/442d0677-9881-4717-9721-70c42e9b38a0.png)

![](https://imgkr.cn-bj.ufileos.com/408eaf89-6d6a-4037-8b4a-a9aed83c564a.png)

最后得到 **C** 语言源文件。

![](https://imgkr.cn-bj.ufileos.com/02dc2064-83a9-4ca7-8dd8-4ee740d5a00c.png)

#### 5. 添加源文件

打开 **keil uVision** 

![](https://imgkr.cn-bj.ufileos.com/eebdad8b-6833-4cbf-8e4c-930ffa85d663.png)

右键，**Source Group 1** ，选择刚刚的 **C语言** 源文件。

![](https://imgkr.cn-bj.ufileos.com/3fe06aea-5390-4e75-86ae-4e934835a4e2.png)

点击②添加，③关闭。

这时 **Source Group 1** 多了个 **+** 

![](https://imgkr.cn-bj.ufileos.com/55a4d50d-5345-47c0-a2f4-d8219db2f540.png)

展开，双击源文件，就可以编写源文件了。

#### 6. 生成hex二进制文件

编写好源文件后，右键 **Target 1** ，选择图中的 **Options for Target 1...** 。

![](https://imgkr.cn-bj.ufileos.com/cc69eddb-5bf6-4b1c-bf71-72023d406c9c.png)

![](https://imgkr.cn-bj.ufileos.com/0d87fc0e-4b36-4ac0-ab07-6ba60081f184.png)

选择 **Output** ，把 **Create HEX File** 打上 ***√*** ，默认是没有 ***√*** 的。然后点击OK，即可。

#### 7. 编译文件

找到工具栏

![](https://imgkr.cn-bj.ufileos.com/4965f55a-de21-4360-a129-d07a6d6bab7a.png)

①是转换和编译按钮，一般通过①的第一个按钮检查自己的代码有没有错，第二个按钮生成HEX文件。

②是调试按钮，设置好段点后，就可以对代码进行调试了。

#### 8. 检查是否生成HEX文件

如果代码没有报错。

![](https://imgkr.cn-bj.ufileos.com/98fc074e-6583-4558-b7c6-5d18ecffa5be.png)

打开建立的文件 **D://MCU/experiment/** 这是我们会看到该目录下有个 **experiment.hex** 文件。

在 **ISIS** 中双击 **AT89C51** 芯片，找到这个 **experiment.hex** 文件，即可进行仿真了。

### 四. 总结

多练习，熟能生巧，不熟悉就谈不上进步。

### 诗情画意

> <center>浣溪沙</center>
> <center>晏殊</center>
> <center>一曲新词酒一杯，去年天气旧亭台。夕阳西下几时回？</center>
> <center>无可奈何花落去，似曾相识燕归来。小园香径独徘徊。</center>

