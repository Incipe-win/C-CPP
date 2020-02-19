#include<bits/stdc++.h>
using namespace std;

const int maxn=100;

bool prime[maxn+1];

void IsPrime(int n) {
    memset(prime,true,sizeof(prime));
    for(int i=3; i<=sqrt(n); i+=2 ) {
        if(prime[i])
            for(int j=i+i; j<=n; j+=i )
                prime[j]=false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n=100;
    IsPrime(n);
    for(int i=3; i<=100; i+=2) {
        if(prime[i])
            cout<<i<<" ";
    }
    return 0;
}
