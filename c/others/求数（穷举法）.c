#include<stdio.h>
#include<math.h>
int main()
{
    long i,n,m;
    for(i=1;i<=100000;i++)
    {
        n=sqrt(i+100);
        m=sqrt(i+168);
        if(n*n==(i+100)&&m*m==(i+168))
            printf("%ld\n",i);
    }
    return 0;
}
