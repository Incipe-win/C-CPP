# piano
### 两个版本一个是master分支只拥有钢琴功能，dev_game分支有类似钢琴游戏的功能，优先后者。

 基于arm平台6818开发板的钢琴游戏，本代码基于开源代码修改



使用步骤
========
1.将include/、lib/、source/拷贝到ubuntu中
2.执行make编译，得到piano

3.将bin/、res/、lib/以及piano拷贝到开发板中
4.执行如下命令，设置环境变量：
   export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib/

5.执行程序：
   ./piano