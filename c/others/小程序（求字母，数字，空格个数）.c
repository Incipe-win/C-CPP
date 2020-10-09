#include<stdio.h>
int main()
{
    int s=0,i=0,j=0,n;
    printf("请输入:");
    while((n=getchar())!='\n')
    {
        if(n>='0'&&n<='9')
            s++;
        else if((n>='a'&&n<='z')||(n>='A'&&n<='Z'))
            i++;
        else if(n==' ')
            j++;
    }
    printf("字母为:%d\n",i);
    printf("数字为:%d\n",s);
    printf("空格为:%d\n",j);
    return 0;
}
