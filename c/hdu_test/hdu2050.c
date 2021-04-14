#include<stdio.h>
int main()
{
	long long n,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",2*n*n-n+1);
	}
	return 0;
}
