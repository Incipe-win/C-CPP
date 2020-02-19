/*hdu2051*/

#include<stdio.h>
int main()
{
	int n,s[6400];
	while(scanf("%d",&n)!=EOF)
	{
		int i=0;
		while(n)
		{
			s[i++]=(int)n%2;
			n/=2;
		}
		if(i==0)
		{
			s[0]=0;
			i=1;
		}
		while(i--)
			printf("%d",s[i]);
		printf("\n");
	}
	return 0;
}
		
