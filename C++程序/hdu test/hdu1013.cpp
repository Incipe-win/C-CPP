#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while(cin>>str&&str!="0")
    {
        int sum=0;
        for(int i=0;i<str.length();i++)
        {
            sum+=str[i]-'0';
            if(sum>=10)
            {
                sum=sum%10+sum/10;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}