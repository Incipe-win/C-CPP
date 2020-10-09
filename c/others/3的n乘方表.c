#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,s;
    scanf("%d",&n);
    while(1)
    {
        for(i=0; i<=n; i++)
        {
            s=pow(3,i);
            printf("pow(3,%d)=%d\n",i,s);
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
