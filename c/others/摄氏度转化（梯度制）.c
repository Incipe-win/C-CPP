#include<stdio.h>
int main()
{
    int lower,upper,n,F;
    double C;
    while(1)
    {
        scanf("%d %d",&lower,&upper);
        if(lower>upper)
            printf("不符合条件");
        else
        {
            printf("转化后温度为:\n");
            for(F=lower; F<=upper; F++)
            {
                C=5*(F*1.0-32)/9;
                printf("%d  %.1f\n",F,C);
                F=F+1;
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
