#include<stdio.h>
int main()
{
    int a,n,s=0,m;
    printf("请输入数字a：");
    scanf("%d",&a);
    printf("请输入个数n：");
    scanf("%d",&n);
    m=a;
    for(int i=1;i<=n;i++)
    {
       s=s+m;
       m=10*m+a;
    }
    printf("结果为：");
    printf("%d",s);
    return 0;
}
