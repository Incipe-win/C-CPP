#include <stdio.h>

int main()
{
    int n;
    long long ans[60] = {};
    ans[1] = 3;
    ans[2] = 6;
    ans[3] = 6;
    for(int i = 4; i <= 55; i++)
      ans[i] = ans[i-1] + 2 * ans[i-2];
    while(scanf("%d",&n)!=EOF)
        printf("%lld\n",ans[n]);
    return 0;
}
