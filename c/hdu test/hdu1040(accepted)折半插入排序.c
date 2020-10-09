/*hdu1040’€∞Î≤Â»Î≈≈–Ú*/

#include<stdio.h>

void BInsertSort(int a[],int n);

int main()
{
    int num;
    scanf("%d",&num);
    getchar();
    while(num--)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        BInsertSort(a,n);
        for(int i=1; i<=n; i++)
        {
            if(i==n)
                printf("%d\n",a[i]);
            else
                printf("%d ",a[i]);
        }
    }
    return 0;
}

void BInsertSort(int a[],int n)
{
    int low,high,m;
    for(int i=2; i<=n; i++)
    {
        a[0]=a[i];
        low=1;
        high=i-1;
        while(low<=high)
        {
            m=(low+high)/2;
            if(a[0]<a[m])
                high=m-1;
            else
                low=m+1;
        }
        int j;
        for(j=i-1; j>=high+1; --j)
            a[j+1]=a[j];
        a[high+1]=a[0];
    }
}
