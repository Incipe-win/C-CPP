/*hdu1008*/

#include<stdio.h>

int main()
{
    int n,time,start,temp;
    while(~scanf("%d",&n))
    {
        int f[n];//停留的层数
        time=start=0;//总时间和一开始的层数
        if(n==0)
            break;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&f[i]);//赋值
        }
        temp=f[1];
        temp=temp*6+5;
        if(n==1)
            printf("%d\n",temp);
        else
        {
            for(int i=1; i<n; i++)
            {
                if(f[i]>f[i+1])
                    time+=(f[i]-f[i+1])*4+5;
                else
                    time+=(f[i+1]-f[i])*6+5;
            }//进行运算
            printf("%d\n",time+temp);
        }
    }
    return 0;
}
