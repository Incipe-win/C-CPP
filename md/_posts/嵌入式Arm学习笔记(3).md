---
title: 嵌入式学习笔记(3)
categories: 
- IOT
tags: 
- 博客
---

## ARM指令集

### 精简指令集设计理念(The  RISC design philosophy)

+ 设计原则(Design rules)
  + 指令"短小精悍"
  + 应用流水线技术设计
  + 大量采用寄存器
  + Load/Store存储结构

### ARM指令集特点

1. 所有指令都是32位
   1. 大多数指令都在单周期内完成
   2. 所有指令都可以条件执行
   3. ARM指令为Load/Store类型
   4. 基本指令仅36条，分为五类
   5. 有9种寻址方式
   6. 指令集可以通过协处理器扩展
2. ARM指令是加载/存储(Load/Store)型
   1. 指令集仅能处理寄存器中的数据，处理结果都要放回寄存器中
   2. 对系统存储器的访问则需要通过专门的Load/Store指令来完成
3. ARM指令可以分为五大类
   1. 数据处理指令
   2. 算术运算指令
   3. 逻辑指令
   4. 比较指令
   5. 乘法指令
   6. 分支转移指令
   7. Load/Store指令
4. ARM指令有9种寻址方式
   1. 寄存器寻址
   2. 立即寻址
   3. 寄存器偏移寻址
   4. 寄存器间接寻址
   5. 基址寻址
   6. 堆栈寻址
   7. 多寄存器寻址
   8. 块拷贝寻址
   9. 相对寻址

### 数据处理指令(Data Processing Instructions)

+ **Syntax: \<opcode(指令)>{\<cond(指令执行条件)>}{S(状态位)} <Rd(目的地址)>, <N(源数据)>{, \<opcode2>}**
+ <>括号内是必须的，{}括号内的是可选的

#### MOV

+ MOV Move a 32-bit value into a register Rd = N
+ MVN move the NOT of the 32-bit value into a register Rd = ~N

Example1：

````assembly
MOV R5, #5
MOV R7, #8
MOV R7, R5	;let R7 = R5
````

````assem
MVN R1, #0xFF	;R1 = 0xFFFFFFFF00
;0xFF转化为二进制
;0000 0000 0000 0000 0000 0000 1111 1111
;取反得到
;1111 1111 1111 1111 1111 1111 0000 0000
;即0xFFFFFF00
````

#### 带有{, \<opcode2>的指令

Example2：

````assembly
MOV R5, #5
MOV R7, #8
MOV R7, R5, LSL #2	;let R7 = R5 * 4 = (R5 << 2)
;LSL左移指令
;左移一位×2,右移一位÷2
````

#### 带有{S}的指令

Example3：

请回顾下CPSR的格式

![当前程序状态寄存器](https://i.loli.net/2020/03/18/ypGErWXQstfHBSi.png)

````assembly
CPSR = nzcvqiFt_USER
R0 = 0X00000000
R1 = 0X80000004
MOVS R0, R1, LSL #1
;结果
;更新CPSR的值,影响了C标志位
;CPSR = nzCvqiFt_USER
;R0 = R1 << 2
;把R1左移两位值赋给R0
;即R0 = 0x00000008
;R1 = 0x80000004
````

### 算术运算指令(Arithmetic Instructions)

+ 算术指令实现32位有符号和无符号值的加减运算
+ **Syntax: \<instruction>{\<cond>}{S} Rd, Rn, N**

#### SUB

Example1：

````assembly
R0 = 0x00000000
R1 = 0x00000002
R2 = 0x00000001
SUB R0, R1, R2
;结果
;R0 = R1 - R2 = 0x00000001
````

#### RSB

Example2：

+ 反向减法，交换减数与被减数的位置

````assembly
R0 = 0X00000000
R1 = 0X00000077
RSB R0, R1, #0
;结果
;R0 = 0x0 - R1
;即R0 = -R1 = 0xFFFFFF89
;-R1就是R1的补码
````



#### 带有{S}的指令

Example3：

````assembly
CPSR = nzcvqiFt_USER
R1 = 0X00000001
SUBS R1, R1, #1
;结果
;CPSR = nZCvqiFt_USER
;R1 = 0X00000000
````

#### 带有{, \<opcode2>的指令

Example4：

````assembly
R0 = 0X00000000
R1 = 0X00000005
ADD R0, R1, R1, LSL #1
;R0 = R1 + R1 << 1
;结果
;R0 = 0x0000000f
;R1 = 0x00000005
````

### 逻辑指令(Logical Instructions)

+ 逻辑指令对两个源寄存器执行按位的逻辑操作
+ **\<Syntax>: \<instruction> {\<cond>}{S} Rd, Rn, N**

#### ORR

Example1：

````assembly
R0 = 0X00000000
R1 = 0X02040608
R2 = 0X10305070
ORR R0, R1, R2
;R0 = R1 OR R2
;或,有1为1,无1为0
;R0 = 0x12345678
````

	#### BIC(位清除指令)

Example2：

````assembly
R1 = 0B1111	;二进制
R2 = 0B0101
BIC R0, R1, R2
;相当于R0 = R1 AND (NOT)R2
;结果
;R0 = 0B1010
;(NOT)R2 = 1010
;1010 AND 1111 = 1010
````

### 比较指令(Comparison Instructions)

+ 比较指令用于比较或测试具有32位值的寄存器。它们根据结果更新cpsr标志位，但不影响其他寄存器
+ S后缀对于更新标志的比较指令来说是不必要的
+ **Syntax: \<instruction>{\<cond>} Rn, N**

#### CMP

Example1：

````assembly
CPSR = nzcvqiFt_USER
R0 = 4
R9 = 4
CMP R0, R9
;结果
;CPSR = nZcvqiFt_USER
;更新了Z标志位
````

### 乘法指令(Multiply Instructions)

+ 乘法指令将一对寄存器的内容相乘，并根据指令将结果累积到另一个寄存器中。长乘法累积到一对表示64位值的寄存器上。最后的结果放在一个目的寄存器或一对寄存器中
+ Syntax
  + **MLA{\<cond>}{S} Rd, Rm, Rs, Rn**
  + **MUL{\<cond>}{S}Rd, Rm, Rs**
  + **MLA: Rd = (Rm * Rs) + Rn**
  + **MUL: Rd = Rm * Rs**
  + **\<instruction>{\<cond>}{S} RdLo, RdHi, Rm, Rs**
  + **SMLAL: [RdHi, RdLo] = [RdHi, RdLo] + (Rm * Rs)**

#### MUL

Example1：

````assembly
R0 = 0X00000000
R1 = 0X00000002
R2 = 0X00000002
MUL R0, R1, R2	;R0 = R1 * R2
;结果
;R0 = 0x00000004
;R1 = 0x00000002
;R2 = 0x00000002
````

#### UMULL(无符号长乘法)

Example2：

````assembly
R0 = 0X00000000;
R1 = 0X00000000;
R2 = 0XF0000002;
R3 = 0X00000002;
UMULL R0, R1, R2, R3	;[R1, R0] = R2 * R3
;结果
;R0 = 0xE0000004 = RdLo
;R1 = 0x00000001 = RdHi
;R2 * R3用32-bit肯定溢出是个64-bit的数，用R0保存低32-bit，R1保存高32-bit
;R2 * R3的结果为 0x00000001E0000004(注意这是十六进制乘法,直接用左移更方便)
````

### 分支指令(Branch Instructions)

+ 分支指令改变执行流，或用于调用例程。这种类型的指令允许程序有子例程、if-then-else结构和循环
+ Syntax
  + **B{\<cond>} label**
  + **BL{\<cond>} label**
  + **BX{\<cond> Rm**
  + **BLX{\<cond>} label | Rm**

#### B

Example1：

````assembly
	B forward
	ADD R1, R2, #4
	ADD R0, R6, #2
	ADD R3, R7, #4
forward
	SUB R1, R2, #4
````

Example2：

````assembly
backward
	ADD R1, R2, #4
	SUB R1, R2, #4
	ADD R4, R6, R7
	B backward
````

#### BL

+ BL指令先将下一条指令的地址拷贝到LR链接寄存器中，然后跳转到指定地址运行程序

````assembly
BL subroutine	;LR -> 下一条指令, 即CMP R1, #5
CMP R1, #5		;比较R1, R5
MOVEQ R1, #0	;if(R1 == 5)then R1 = 0
...
subroutine
<subroutine code>
MOV PC, LR		;return by moving pc = lr
````

### Load/Store指令(Load-Store Instructions)

+ **Load/Store指令用于寄存器和内存间数据的传送**
+ **Load 用于把内存中的数据装载到寄存器中**
+ **Store用于把寄存器中的数据存入内存**
+ **该集合的指令使用频繁，在指令集中最为重要，因为其他指令只能操作寄存器，当数据存放在内存中时，必须先把数据从内存装载到寄存器，执行完后再把寄存器中的数据存储到内存中**

#### 单个寄存器传输(Single-Register Transfer)

+ 用于将单个数据项移入或移出寄存器
+ 支持的数据类型包括有符号的和无符号的字(32位)、半字(16位)和字节
+ Syntax
  + **\<LDR|STR>{\<cond>}{B} Rd, addressing1**
  + **LDR{\<cond>}SB|H|SH Rd, addressing2**
  + **STR{\<cond>}H Rd, addressing2**

Example1：

````assembly
LDR R0, [R1]	;= LDR R0, [R1, #0]
;
;
STR R0, [R1]	;= STR R0, [R1, #0]
````

#### 单寄存器负载存储寻址模式(Single-Register Load-Store Addressing Modes)

|              Index method              |        Data        | Base address register |      Example      |
| :------------------------------------: | :----------------: | :-------------------: | :---------------: |
| Preindex with writeback(前项索引+写回) | mem[base + offset] |     base + offset     | LDR R0, [R1, #4]! |
|                Preindex                | mem[base + offset] |      not updated      | LDR R0, [R1, #4]  |
|          Postindex(后项索引)           |     mem[base]      |     base + offset     | LDR R0, [R1], #4  |

前项索引和后项索引指的是，先访问还是后访问，写回表示写入寄存器。

Example2：

````assembly
R0 = 0x00000000
R1 = 0X00090000
mem32[0x00009000] = 0x01010101
mem32[0x00009004] = 0x02020202
LDR R0, [R1, #4]!
LDR R0, [R1, #4]
LDR R0, [R1], #4
;Preindexing with writeback
;R0 = 0x02020202
;R1 = 0x00009004
;Preindexing
;R0 = 0x02020202
;R1 = 0x00009000
;Postindexing
;R0 = 0x01010101
;R1 = 0x00009004
````

#### 多个寄存器传输(Multiple-Register Transfer)

+ Load-store多个寄存器传输指令可以用一条指令在内存和处理器之间传输多个寄存器
+ Syntax
  + **\<LDM|STM>{\<cond>}\<addressing mode> Rn{!}, \<register>{^}**

| Addressing mode |      Description      | Start address  |  End address   |    Rn!     |
| :-------------: | :-------------------: | :------------: | :------------: | :--------: |
|       IA        | increment(增加) after |       Rn       | Rn + 4 * N - 4 | Rn + 4 * N |
|       IB        |   increment before    |     Rn + 4     |   Rn + 4 * N   | Rn + 4 * N |
|       DA        | decrement(减少) after | Rn - 4 * N + 4 |       Rn       | Rn - 4 * N |
|       DB        |   decrement before    |   Rn - 4 * N   |     Rn - 4     | Rn - 4 * N |

Example3：

````assembly
mem32[0x80018] = 0x03
mem32[0x80014] = 0x02
mem32[0x80010] = 0x01
R0 = 0X00080010
R1 = 0X00000000
R2 = 0X00000000
R3 = 0X00000000
LDMIA R0!, {R1-R3}	;不是R1减去R3,是R1到R3中间的寄存器
;结果
;R0 = 0x0008001c
;R1 = 0x00000001
;R2 = 0x00000002
;R3 = 0x00000003
````

Example4：

![地址图](https://i.loli.net/2020/03/19/rdCbxORFeEc7Jy5.png)

````assembly
;R9 points to start of source data
;R10 points to start of destination data
;R11 points to end of the source
loop
	LDMIA R9!, {R0-R7}
	STMIA R10!, {R0-R7}
	CMP R9, R11
	BNE loop
;这段代码的把R9~R11寄存器的内容添加到内存
````

| Addressing mode |      Description      |  Pop  | = LDM | Push  | =  STM |
| :-------------: | :-------------------: | :---: | :---: | :---: | :----: |
|       FA        | full ascending(满增)  | LDMFA | LDMDA | STMFA | STMIB  |
|       FD        | full descending(满减) | LDMFD | LDMIA | STMIA | STMDB  |
|       EA        |    empty ascending    | LDMEA | LDMDB | STMEA | STMIA  |
|       ED        |   empty descending    | LDMED | LDMIB | STMED | STMDA  |

Example5：

````assembly
R1 = 0x00000002
R4 = 0x00000003
SP = 0x00080014
STMFD SP!, {R1, R4}
;结果
;R1 = Ox00000002
;R4 = 0x00000003
;SP = 0x0008000C
````

Example6：

````assembly
R1 = 0x00000002
R4 = 0x00000003
SP = 0x00080010
STMED SP!, {R1, R4}
;结果
;R1 = 0x00000002
;R4 = 0x00000003
;SP = 0x00080008
````

### 交换指令(Swap Instructions)

+ Syntax
  + **SWP{B}{\<cond>} Rd, Rm, [Rn]**

Example1：

````assembly
mem32[0x9000] = 0x12345678
R0 = 0x00000000
R1 = 0x11112222
R2 = 0x00009000
SWP R0, R1, [R2]
;结果
mem32[0x9000] = 0x11112222
R0 = 0x12345678
R1 = 0x11112222
R2 = 0x00009000
````

### 软中断指令(Software Interrupt Instruction)

+ Syntax
  + SWI{code} immed_24

+ 软件中断指令SWI产生软件异常中断，用来实现用户模式到特权模式的切换。用于在用户模式下对操作系统中特权模式的程序的调用；它将处理器置于管理（_svc）模式，中断矢量地址为0x08

## 总结

ARM指令很多，不是一时半会可以记住的，代码敲的多了就有感觉了。想深度学习还是要多看书！

**才疏学浅，望雅正！**