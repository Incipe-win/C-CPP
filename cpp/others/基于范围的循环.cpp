#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int a[]={2,1,4,3,5};
    for(auto i:a)
    {
        cout<<i<<endl;
    }
    for(auto& i:a)
    {
        i=2*i;
    }
    for(auto i:a)
    {
        cout<<i<<endl;
    }
    return 0;
}

//基于范围的循环，只支持for
