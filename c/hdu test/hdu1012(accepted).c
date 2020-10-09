/*hdu1012*/

#include<stdio.h>

int main()
{
    int deno=1;
    double temp,sum=0.0;
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    for(int i=3; i<=9; i++)
    {
        for(int j=i; j>=1; j--)
        {
            deno*=j;
        }
        temp=(double)1/deno;
        sum+=temp;
        printf("%d %.9lf\n",i,sum+2.5);
        deno=1;
    }
    return 0;
}
