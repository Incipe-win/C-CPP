/*本程序为四则运算表达式求值系统，用于计算带小括号的四则运算表达式求值。
具体算法：
    先将字符串处理成操作单元（操作数或操作符），再利用栈根据四则运算
的运算法则进行计算，最后得出结果。*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int Expmax_length = 1001;  //表达式最大长度，可根据适当情况调整
struct Ope_unit {                //定义操作单元
  int flag;     //=1表示是操作数 =0表示是操作符 -1表示符号单元
  char oper;    //操作符
  double real;  //操作数，为双精度浮点数
};

void Display();  //菜单
int Check(char Exp_arry[]);
void Evalua();  //先调用Conver操作单元化，再调用Calculate函数计算结果并输出
int Conver(struct Ope_unit Opeunit_arry[],
           char Exp_arry[]);           //将字符串处理成操作单元
int Isoper(char ch);                   //判断合法字符（+ - * / ( ) =）
int Ope_Compar(char ope1, char ope2);  //操作符运算优先级比较
double Calculate(struct Ope_unit Opeunit_arry[], int Opeunit_count,
                 int &flag);  //用栈计算表达式结果
double Four_arithm(double x, double y, char oper);  //四则运算

int main() {
  int select, choice;
  Display();
  printf("请输入欲执行功能对应的数字：");
  scanf("%d", &select);
  printf("\n");
  while (1) {
    switch (select) {
      case 1:
        Evalua();
        break;
      case 0:
        return 0;
      default:
        printf("无该数字对应的功能，程序结束!\n");
        break;
    }
    printf("是否结束:是 ? 1 : 0\n请输入你的选择:");
    scanf("%d", &choice);
    if (choice == 1) break;
  }
  system("pause");
  return 0;
}

int Check(char Exp_arry[]) {  //检查是否有非法字符，返回1表示不合法，0表示合法
  int Explength = strlen(Exp_arry), i;
  for (i = 0; i < Explength; i++) {
    if (!Isoper(Exp_arry[i]) && Exp_arry[i] != '.' && !isdigit(Exp_arry[i]))
      return 1;
    if (isdigit(Exp_arry[i])) {
      int Dig_number = 0, Cur_positoin = i + 1;
      while (isdigit(Exp_arry[Cur_positoin]) || Exp_arry[Cur_positoin] == '.') {
        Dig_number++;
        Cur_positoin++;
      }
      if (Dig_number >= 16)  //最多能够计算15位有效数字
        return 1;
    }
  }
  return 0;
}

void Evalua() {  //先调用Conver函数将字符串操作单元化，再调用Calculate函数计算结果并输出
  char Exp_arry[Expmax_length];
  int flag = 0;  //假设刚开始不合法，1表达式合法，0不合法
  struct Ope_unit Opeunit_arry[Expmax_length];

  getchar();  //吃掉一个换行符
  printf("请输入四则运算表达式，以=结尾：\n");
  gets(Exp_arry);
  flag = Check(Exp_arry);
  if (flag)
    printf("该表达式不合法！\n");
  else {
    int Opeunit_count = Conver(Opeunit_arry, Exp_arry);
    double ans = Calculate(Opeunit_arry, Opeunit_count, flag);
    if (flag) {
      printf("计算结果为：\n");
      printf("%s%lf\n", Exp_arry, ans);
    } else
      printf("该表达式不合法！\n");
  }
}

int Conver(struct Ope_unit Opeunit_arry[],
           char Exp_arry[]) {  //将字符串操作单元化
  int Explength = strlen(Exp_arry);
  int i, Opeunit_count = 0;
  for (i = 0; i < Explength; i++) {
    if (Isoper(Exp_arry[i]))  //是操作符
    {
      Opeunit_arry[Opeunit_count].flag = 0;
      Opeunit_arry[Opeunit_count++].oper = Exp_arry[i];
    } else  //是操作数
    {
      Opeunit_arry[Opeunit_count].flag = 1;
      char temp[Expmax_length];
      int k = 0;
      for (; isdigit(Exp_arry[i]) || Exp_arry[i] == '.'; i++) {
        temp[k++] = Exp_arry[i];
      }
      i--;
      temp[k] = '\0';
      Opeunit_arry[Opeunit_count].real = atof(temp);  //将字符转化为浮点数

      //负数
      if (Opeunit_count == 1 && Opeunit_arry[Opeunit_count - 1].flag == 0 &&
          Opeunit_arry[Opeunit_count - 1].oper == '-') {
        Opeunit_arry[Opeunit_count - 1].flag = -1;
        Opeunit_arry[Opeunit_count].real *= -1;
      }  // -9
      if (Opeunit_count >= 2 && Opeunit_arry[Opeunit_count - 1].flag == 0 &&
          Opeunit_arry[Opeunit_count - 1].oper == '-' &&
          Opeunit_arry[Opeunit_count - 2].flag == 0 &&
          Opeunit_arry[Opeunit_count - 2].oper != ')') {
        Opeunit_arry[Opeunit_count - 1].flag = -1;
        Opeunit_arry[Opeunit_count].real *= -1;
      }  // )-9

      //正数
      if (Opeunit_count == 1 && Opeunit_arry[Opeunit_count - 1].flag == 0 &&
          Opeunit_arry[Opeunit_count - 1].oper == '+') {
        Opeunit_arry[Opeunit_count - 1].flag = -1;
      }  // +9
      if (Opeunit_count >= 2 && Opeunit_arry[Opeunit_count - 1].flag == 0 &&
          Opeunit_arry[Opeunit_count - 1].oper == '+' &&
          Opeunit_arry[Opeunit_count - 2].flag == 0 &&
          Opeunit_arry[Opeunit_count - 2].oper != ')') {
        Opeunit_arry[Opeunit_count - 1].flag = -1;
      }  // )+9
      Opeunit_count++;
    }
  }
  /*for(i=0;i<Opeunit_count;i++)
  {//查看各操作单元是否正确,1是操作数，0是操作符
      if(Opeunit_arry[i].flag == 1)
      printf("该单元是操作数为：%lf\n",Opeunit_arry[i].real);
      else if(Opeunit_arry[i].flag == 0)
      printf("该单元是操作符为：%c\n",Opeunit_arry[i].oper);
      else
      printf("该单元是负号符为：%c\n",Opeunit_arry[i].oper);
  }*/
  return Opeunit_count;
}

double Calculate(struct Ope_unit Opeunit_arry[], int Opeunit_count,
                 int &flag) {  //根据运算规则，利用栈进行计算
  int i, dS_pointer = 0,
         oS_pointer =
             0;  // dS_pointer为操作数栈顶指示器，oS_pointer为操作符栈顶指示器
  double Dig_stack[Expmax_length];  //操作数栈（顺序存储结构）
  char Ope_stack[Expmax_length];    //操作符栈

  for (i = 0; i < Opeunit_count - 1; i++) {
    if (Opeunit_arry[i].flag != -1) {
      //是操作数
      if (Opeunit_arry[i].flag) {
        Dig_stack[dS_pointer++] = Opeunit_arry[i].real;  //入操作数栈
        // printf("%lf\n",Digit[dS_pointer-1]);
      } else {
        //是操作符 + - * / ( )
        //操作符栈为空或者左括号 入栈
        if (oS_pointer == 0 || Opeunit_arry[i].oper == '(') {
          Ope_stack[oS_pointer++] = Opeunit_arry[i].oper;
          // printf("%oS_pointer\Ope_u_count",Operator[oS_pointer-1]);
        } else {
          //是右括号将运算符一直出栈，直到遇见左括号
          if (Opeunit_arry[i].oper == ')') {
            oS_pointer--;  //指向栈顶
            dS_pointer--;  //指向栈顶
            while (Ope_stack[oS_pointer] != '(' && oS_pointer != 0) {
              Dig_stack[dS_pointer - 1] = Four_arithm(
                  Dig_stack[dS_pointer - 1], Dig_stack[dS_pointer],
                  Ope_stack[oS_pointer--]);  // oS_pointer--为操作符出栈

              dS_pointer--;  //前一个操作数出栈
              // printf("操作数栈顶元素等于%lf\n",Digit[dS_pointer]);
            }
            oS_pointer--;  //左括号出栈

            oS_pointer++;  //恢复指向栈顶之上
            dS_pointer++;
          } else if (Ope_Compar(Opeunit_arry[i].oper,
                                Ope_stack[oS_pointer - 1])) {
            //和栈顶元素比较
            Ope_stack[oS_pointer++] = Opeunit_arry[i].oper;
            // printf("%oS_pointer\Ope_u_count",Operator[oS_pointer-1]);
          } else {
            //运算符出栈，再将该操作符入栈
            oS_pointer--;  //指向栈顶
            dS_pointer--;  //指向栈顶
            while (Ope_Compar(Opeunit_arry[i].oper, Ope_stack[oS_pointer]) ==
                       0 &&
                   oS_pointer != -1) {  //当前操作符比栈顶操作符优先级高
              Dig_stack[dS_pointer - 1] =
                  Four_arithm(Dig_stack[dS_pointer - 1], Dig_stack[dS_pointer],
                              Ope_stack[oS_pointer--]);
              dS_pointer--;
              // printf("操作数栈顶元素等于%lf\n",Digit[dS_pointer]);
            }
            oS_pointer++;  //恢复指向栈顶之上
            dS_pointer++;
            Ope_stack[oS_pointer++] = Opeunit_arry[i].oper;
          }
        }
      }
    }
  }
  /*for(i=0;i<oS_pointer;i++)
      printf("操作符栈%oS_pointer\Ope_u_count",Operator[i]);
  for(i=0;i<dS_pointer;i++)
      printf("操作数栈%lf\n",Digit[i]);*/
  oS_pointer--;  //指向栈顶元素
  dS_pointer--;  //指向栈顶元素
  while (oS_pointer != -1) {
    Dig_stack[dS_pointer - 1] =
        Four_arithm(Dig_stack[dS_pointer - 1], Dig_stack[dS_pointer],
                    Ope_stack[oS_pointer--]);  // oS_pointer--为操作符出栈
    dS_pointer--;                              //前一个操作数出栈
    // printf("操作数栈顶元素为%lf\Ope_u_count",Digit[dS_pointer]);
  }
  // printf("%dS_pointer,%dS_pointer\n",oS_pointer,dS_pointer);
  if (oS_pointer == -1 && dS_pointer == 0) flag = 1;  //为1表示表达式合法
  return Dig_stack[0];
}

int Ope_Compar(char ope1, char ope2) {  //操作符运算优先级比较
  char list[] = {"(+-*/"};
  int map[5][5] = {//先行后列，行比列的运算级优先级低为0，高为1
                   //        ( + - * /
                   /*  (  */ 1, 0, 0, 0, 0,
                   /*  +  */ 1, 0, 0, 0, 0,
                   /*  -  */ 1, 0, 0, 0, 0,
                   /*  *  */ 1, 1, 1, 0, 0,
                   /*  /  */ 1, 1, 1, 0, 0};
  int i, j;
  for (i = 0; i < 5; i++)
    if (ope1 == list[i]) break;
  for (j = 0; j < 5; j++)
    if (ope2 == list[j]) break;
  return map[i][j];
}

double Four_arithm(double x, double y, char oper) {  //四则运算
  switch (oper)  //保证不含其它运算符
  {
    case '+':
      return x + y;
    case '-':
      return x - y;
    case '*':
      return x * y;
    case '/':
      return x / y;  // y不能为0
    default:
      return 0;
  }
}

int Isoper(char ch) {  //判断合法字符  + - * / ( ) =
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' ||
      ch == ')' || ch == '=')
    return 1;
  return 0;
}

void Display() {  //打印菜单
  system("cls");
  printf(
      "/***********************************************************************"
      "*******/\n");
  printf("\t\t       欢迎使用本四则运算表达式求值系统\n");
  printf("\n\t\t1 四则运算表达式求值\n");
  printf("\n\t\t0 退出\n");
  printf(
      "/***********************************************************************"
      "*******/\n");
}