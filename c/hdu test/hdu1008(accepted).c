/*hdu1008*/

#include<stdio.h>

int main()
{
    int n,time,start;
    while(~scanf("%d",&n))
    {
        int f[n];//停留的层数
        time=start=0;//总时间和一开始的层数
        if(n==0)break;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&f[i]);//赋值
        }
        for(int i=1;i<=n;i++)
        {
            if(f[i]>start)
                time+=(f[i]-start)*6;
            else
                time+=(start-f[i])*4;
            start=f[i];
            time+=5;
        }//进行运算
        printf("%d\n",time);
    }
    return 0;
}
