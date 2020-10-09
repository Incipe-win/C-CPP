#include<stdio.h>
int main()
{
    float x,a,b;
    int m,n;
    while(1)
    {
        scanf("%f",&x);
        if(x!=0)
            m=1;
        if(x==0)
            m=2;
        switch(m)
        {
        case 1:
        {
            a=1/x;
            printf("f(%.1f)=%.1f\n",x,a);
            break;
        }
        case 2:
        {
            b=0;
            printf("f(%.1f)=%.1f\n",x,b);
            break;
        }
        }
        printf("是否结束程序 1.是 2.否\n");
        printf("请输入你的选择:");
        scanf("%d",&n);
        if(n==1)
            break;
        if(n==2)
            printf("\n");
    }
    return 0;
}
