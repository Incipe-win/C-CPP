#include<stdio.h>
int main()
{
    float n,s=100.0;
    n=s/2;
    for(int i=2;i<=10;i++)
    {
        s=s+2*n;
        n=n/2;
    }
    printf("The total of road is %f meters\n",s);
    printf("The tenth is %f meters\n",n);
    return 0;
}
