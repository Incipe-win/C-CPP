#include<stdio.h>
int main()
{
    int n,i,m;
    float s,b;
    s=1;
    for(;;)
    {
        scanf("%d",&n);
        for(i=2; i<=n; i++)
        {
            b=1.0/i;
            s=s+b;
        }
        printf("%.6f\n",s);
        printf("是否结束程序 1.是 2.否\n");
        printf("请输入你的选择:");
        scanf("%d",&m);
        if(m==1)
            break;
        if(m==2)
            printf("\n");
    }
    return 0;
}

