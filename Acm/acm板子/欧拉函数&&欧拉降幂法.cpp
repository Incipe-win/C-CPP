long long FastPow(long long a,long long c)
{
    long long res=1;
    a%=1337;
    while(c)
    {
        if(c&1)
        {
            res*=a;
            res%=1337;
        }
        a*=a;
        a%=1337;
        c>>=1;
    }
    return res;
}

int eular(int n)
{
    int ret=1,i;
    for(i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            n/=i;
            ret*=i-1;
            while(n%i==0)
            {
                n/=i;
                ret*=i;
            }
        }
    }
    if(n>1)
        ret*=n-1;
    return ret;
}

int superPow(int a, int* b, int bSize){
    int n = 0,temp;
    temp=eular(1337);
    if(bSize==0){
        return 0;
    }
    for(int i=0;i<bSize;i++){
        n*=10;
        n+=b[i];
        n%=temp;
        n+=temp;
    }
    return FastPow(a,n);
}