/*hdu1040ºÚµ•≈≈–Ú*/

#include<stdio.h>

void InsertSort(int a[],int n);

int main()
{
    int num;
    scanf("%d",&num);
    getchar();
    while(num--)
    {
        int n;
        scanf("%d",&n);
        int a[n+1];
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        InsertSort(a,n);
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

void InsertSort(int a[],int n)
{
    int j;
    for(int i=2; i<=n; ++i)
        if(a[i]<a[i-1])
        {
            a[0]=a[i];
            a[i]=a[i-1];
            for(j=i-2; a[0]<a[j]; --j)
                a[j+1]=a[j];
            a[j+1]=a[0];
        }
}
