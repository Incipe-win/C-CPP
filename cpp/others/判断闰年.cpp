#include <iostream>

using namespace std;

int main()
{
    int year;
    bool isLeapyear;
    cout<<"Enter the year:";
    cin>>year;
    isLeapyear=((year%4==0&&year%100!=0)||(year%400==0));
    if(isLeapyear)
    {
        cout<<year<<"is a leap year"<<endl;
    }
    else
    {
        cout<<year<<"is not a leap year"<<endl;
    }
    return 0;
}
