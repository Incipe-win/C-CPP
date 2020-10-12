/*hdu1037*/

#include<stdio.h>

#define HEIGH 168

int main()
{
    int a1,a2,a3;//三个通道高度
    while(scanf("%d %d %d",&a1,&a2,&a3)!=EOF)
    {
        if(a1>HEIGH&&a2>HEIGH&&a3>HEIGH)
            printf("NO CRASH\n");
        else if(a1<=HEIGH)
            printf("CRASH %d\n",a1);
        else if(a2<=HEIGH)
            printf("CRASH %d\n",a2);
        else if(a3<=HEIGH)
            printf("CRASH %d\n",a3);
    }
    return 0;
}
/*学好英语*/
