#include<stdio.h>
int main()
{
    int n,m,temp,a,b;
    printf("最小公倍数与最大公因数\n");
    printf("    请输入两个数:");
    scanf(" %d %d",&n,&m);
    if(n<m)
    {
        temp=n;
        n=m;
        m=temp;
    }
    a=n;
    b=m;
    while(b!=0)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    printf("    最小公倍数为:%d\n",n*m/a);
    printf("    最大公因数为:%d",a);
    return 0;
}
