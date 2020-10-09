#include<iostream>
using namespace std;

void mo_ve(char src,char dest)
{
     cout<<src<<"-->"<<dest<<endl;
}

void hanoi(int n,char src,char medium,char dest)
{
     if(n==1)
          mo_ve(src,dest);
     else
     {
          hanoi(n-1,src,dest,medium);
          mo_ve(src,dest);
          hanoi(n-1,medium,src,dest);
     }
}

int main()
{
     int m;
     cout<<"Enter the number of diskes:";
     cin>>m;
     cout<<"the steps to moving "<<m<<"diskes:"<<endl;
     hanoi(m,'A','B','C');
     return 0;
}
