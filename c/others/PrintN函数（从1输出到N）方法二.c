#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    void PrintN(int N);
    PrintN(N);
    printf("\n");
    return 0;
}

void PrintN(int N)
{
    if(N)
    {
        PrintN(N-1);
        printf("%d\t",N);
        if(N%9==0)
        {
            printf("\n");
        }
    }
}
