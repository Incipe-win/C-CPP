#include<stdio.h>
int main()
{
    long f1,f2;
    int i,n;
    f1=1;
    f2=1;
    printf("请输入n：\n");
    scanf("%d",&n);
    printf("斐波那契数列为：\n\n"); 
    for(i=1;i<=n;i++)
    {
        printf("%-8ld %-8ld ",f1,f2);
        if(i%5==0)
            printf("\n");
        f1=f1+f2;
        f2=f1+f2;
    }
    return 0;
}
