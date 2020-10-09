#include<stdio.h>
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		printf("+");
		for(int i=1;i<=n;i++)
			printf("-");
		printf("+\n");
		for(int i=1;i<=m;i++)
		{
			printf("|");
			for(int j=1;j<=n;j++)
				printf(" ");
			printf("|\n");
		}
		printf("+");
		for(int i=1;i<=n;i++)
			printf("-");
		printf("+\n\n");
	}
	return 0;
}
	
