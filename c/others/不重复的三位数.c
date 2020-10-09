#include<stdio.h>
int main()
{
    int i,j,k,n=0;
    printf("\n有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？ \n\n");
    printf("                          所有的三位数为:\n\n");
    for(i=1;i<5;i++)
    {
        for(j=1;j<5;j++)
        {
            for(k=1;k<5;k++)
            {
                if(k!=j&&k!=i&&i!=j)
                {
                    n++;
                    printf("%d%d%d ",i,j,k);
                }
            }
        }
    }
    printf("\n\n");
    printf("                            个数为:%d\n",n);
    return 0;
}
