#include<bits/stdc++.h>
//#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int num;
		double higher,temp=0.0;
		cin>>num;
		while(num--)
		{
			cin>>higher;
			if(higher>temp)
				temp=higher;
		}
		cout<<fixed;
		cout<<setprecision(2)<<temp<<endl;
	}
	return 0;
}