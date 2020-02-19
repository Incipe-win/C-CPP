/*hdu1032*/

#include<stdio.h>

int main()
{
    int n,m,temp,max;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        printf("%d %d ",n,m);
        if(n>m)
        {
            temp=n;
            n=m;
            m=temp;
        }
        max=0;
        for(int i=n;i<=m;i++)
        {
            int t=i,flag=1;
            while(t!=1)
            {
                if(t%2==0)
                    t/=2;
                else
                    t=(t*3+1);
                flag++;
            }
            if(flag>max)
                max=flag;
        }
        printf("%d\n",max);
    }
    return 0;
}


/*水题，还是要懂点英文啊,看了好久都不知题目所云*/
