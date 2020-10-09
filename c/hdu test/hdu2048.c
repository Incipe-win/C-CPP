#include<stdio.h>
int main()
{
	int n;
	long long ans[25];
	ans[1]=0;
	ans[2]=1;
	for(int i=3;i<25;i++)
		ans[i]=(i-1)*ans[i-1]+(i-1)*ans[i-2];
	scanf("%d",&n);
	while(n--)
	{
		int t;
		scanf("%d",&t);
		long long sum=1;
		for(int i=1;i<=t;i++)
			sum*=i;
		printf("%.2lf%%\n",ans[t]*100.0/sum);
	}
	return 0;
}
