#include<bits/stdc++.h>
using namespace std;

int main()
{
	char ch[100017];
	while(gets(ch)!='\0')
	{
		if(strcmp(ch, "#")==0)
			break;
		char *p,i;
		int sum=0,j=1;
		p=ch;
		while(*p)
		{
			if(*p==' ')
				sum+=j*0;
			else
			{
				for(i='A'; i<='Z'; i++)
				{
					if(*p==i)
					{
						sum+=j*(int)(i-64);
						break;
					}
				}
			}
			j++;
			p++;
		}
		cout<<sum<<endl;
	}
	return 0;
}