/*hdu1040ц╟ещеепР*/

#include<stdio.h>

int main()
{
    int n,num;
    scanf("%d",&n);//
    getchar();
    while(n--)
    {
        scanf("%d",&num);
        int s[num];
        for(int i=0;i<num;i++)
        {
            scanf("%d",&s[i]);
        }
        for(int i=0;i<num;i++)
            for(int j=0;j<num-1;j++)
        {
            if(s[j]>s[j+1])
            {
                int temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
        for(int i=0;i<num;i++)
        {
            if(i==num-1)
                printf("%d\n",s[i]);
            else
                printf("%d ",s[i]);
        }
    }
    return 0;
}

