#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[100017];
    while(cin>>str&&str[0]!='0')
    {
        int sum=0,length;
        length=strlen(str);
        for(int i=0;i<length;i++)
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