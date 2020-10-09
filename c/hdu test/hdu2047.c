#include<stdio.h>
int main()
{
	int n;
	long long ans[45];
	ans[1]=3;
	ans[2]=8;
	for(int i=3;i<=40;i++)
		ans[i]=2*(ans[i-1]+ans[i-2]);
	while(scanf("%d",&n)!=EOF)
		printf("%lld\n",ans[n]);
	return 0;
}
