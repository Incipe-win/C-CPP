#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,cnt=0;
  cin>>n;
  while(n!=1){
    if(n&1){
      n=(3*n+1)/2;
      cnt++;
    }
    else{
      n=n/2;
      cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}