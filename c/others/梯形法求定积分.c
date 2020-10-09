#include<stdio.h>
#include<math.h>
int main()
{
    printf("                                        课程设计第37题用梯形法计算函数的定积分                                     \n\n");
    printf("提示：把积分区间[a，b]等分为n等分（a,b,n的值由程序输入。），可得到若干个小梯形，积分面积就近似为这些小梯形面积之和。\n\n\n");
    float fun(float (*f)(float), float a, float b);//声明函数指针，声明函数fun
    float F1(float x);//声明函数F1
    float a,b;//定义a，b为浮点类型的数
    int m;
    printf("     函数是x*x+2*x+1\n\n");
    while(1)//死循环
    {
        printf("请输入区间下限a和区间上限b:\n");
        scanf("%f%f",&a,&b);
        printf("请输入区间分段数n\n");
        printf("该函数的定积分=                      %f\n\n",fun(F1,a,b));//调用函数指针
        printf("是否结束循环，是：1，否：2\n");
        scanf("%d",&m);
        if(m==1)
        break;
        if(m==2)
        printf("\n");
    }
    return 0;
}


float F1(float x)//引用函数F1
{
    return x*x+2*x+1;//以目标函数x*x+2*x+1的值作为函数返回值返回fun函数，及函数指针
}


float fun(float (*f)(float), float a,float b)//引用函数指针
{
    float s,h;
    int n;//对分成n部分进行赋值
    scanf("%d",&n);
    s=((*f)(a)+(*f)(b))/2;//调用函数F1进行运算
    h=(b-a)/n;//计算每一个小梯形的高
    int i;
    for(i=0; i<n; i++)
    {
        s=(*f)(a + i*h)+s;
    }
    return s*h;
    //计算n个小梯形面积之和，作为返回值返回主函数
}
