#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node
{
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L );

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for ( i=0; i<N; i++ )
    {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;
        L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}

int FactorialSum( List L )
{
    int temp,sum=0;
    while(L!=NULL)
    {
        temp=1;
        for(int i=L->Data;i>=1;--i)
            temp*=i;
        sum+=temp;
        L=L->Next;
    }
    return sum;
}

/*此题就当是链表入门吧*/
