/*hdu1040øÏÀŸ≈≈–Ú*/

#include<stdio.h>

void quicksort(int a[],int low,int high);
int split(int a[],int low,int high);

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        int num,i;
        scanf("%d",&num);
        int a[num];
        for(i=0; i<num; i++)
            scanf("%d",&a[i]);
        quicksort(a,0,num-1);
        for(i=0; i<num; i++)
        {
            if(i==num-1)
                printf("%d\n",a[i]);
            else
                printf("%d ",a[i]);
        }
    }
    return 0;
}

void quicksort(int a[],int low,int high)
{
    int middle;
    if(low>=high)return ;
    middle=split(a,low,high);
    quicksort(a,low,middle-1);
    quicksort(a,middle+1,high);
}

int split(int a[],int low,int high)
{
    int part_element=a[low];
    for(;;)
    {
        while(low<high&&part_element<=a[high])
            high--;
        if(low>=high)
            break;
        a[low++]=a[high];

        while(low<high&&a[low]<=part_element)
            low++;
        if(low>=high)
            break;
        a[high--]=a[low];
    }
    a[high]=part_element;
    return high;//
}
