#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    for(int i=1; i<=9; i++)
        for(int j=1; j<=i; j++)
        {
            cout<<std::left<<setw(4)<<i*j<<' ';
            if(j==i)
                cout<<endl;
        }
    return 0;
}
