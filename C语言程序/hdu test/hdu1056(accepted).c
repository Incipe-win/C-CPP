/*hdu1056*/

#include<stdio.h>

int main()
{
     float c;
     while(scanf("%f",&c)!=EOF)
     {
          if(c==0.00)break;
          float deno,sum=0;
          int i,j=0;
          for(i=2;;i++)
          {
               deno=(float)1/i;
               sum+=deno;
               j++;
               if(sum>=c)break;
          }
          printf("%d card(s)\n",j);
     }
     return 0;
}
