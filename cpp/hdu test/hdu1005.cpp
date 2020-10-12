#include <iostream>
using namespace std;
int arr[50];
int main()
{
    int n,a,b;
    arr[1]=arr[2]=1;
    while(cin>>a>>b>>n)
    {
        if(a==0&&b==0&&n==0)
            break;
        for(int i=3; i<=50; i++)
        {
            arr[i]=(a*arr[i-1]+b*arr[i-2])%7;
        }
        cout<<arr[n%49]<<endl;
 
    }
    return 0;
}