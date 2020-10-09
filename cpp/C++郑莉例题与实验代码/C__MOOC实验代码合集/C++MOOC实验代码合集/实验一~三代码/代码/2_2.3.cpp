#include <iostream>
using namespace std ;

struct MyTimeStruct
{
    unsigned int year;
    unsigned int month;
    unsigned int day;

    unsigned int hour;
    unsigned int min;
    unsigned int sec;

};

int main()
{
    MyTimeStruct myTime= {2015,3,16,12,0,0};

    cout<<"please input year: "<<endl;
    cin>>myTime.year;

    cout<<"please input month: "<<endl;
    cin>>myTime.month;

    cout<<"please input day: "<<endl;
    cin>>myTime.day;

    cout<<"please input hour: "<<endl;
    cin>>myTime.hour;

    cout<<"please input min: "<<endl;
    cin>>myTime.min;

    cout<<"please input sec: "<<endl;
    cin>>myTime.sec;

    cout<<"the time is set to :"<<myTime.year<<"/"
        <<myTime.month<<"/"
        <<myTime.day<<" "
        <<myTime.hour<<":"
        <<myTime.min<<":"
        <<myTime.sec<< endl;

    return 0;
}
