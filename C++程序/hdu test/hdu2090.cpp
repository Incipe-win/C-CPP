#include<bits/stdc++.h>

using namespace std;

int main()
{
	char ch[1000017];
	double a,b,sum=0;
	while(cin>>ch>>a>>b)
	{
		sum+=a*b;
	}
	cout<<fixed<<setprecision(1)<<sum<<endl;
}