#include <stdio.h>
int main()
{
    int i,j,k,l;
    printf("'Water Flower' number is:\n");
    for(i=100;i<1000;i++)
    {
        j=i/100;
        k=i/10%10;
        l=i%10;
        if(100*j+10*k+l==j*j*j+k*k*k+l*l*l)
        {
            printf(" %-5d",i);
        }
    }
    printf("\n");
    return 0;
}
