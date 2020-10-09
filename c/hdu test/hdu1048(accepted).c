#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char fun(char *str);

int main()
{
    char str[200],str1[7],str2[7];
    while(gets(str1)!=NULL)
    {
        char str3[]= {"ENDOFINPUT"};
        if(strcmp(str1,str3)==0)
            break;
        gets(str);
        fun(str);
        gets(str2);
        puts(str);
    }
    return 0;
}

char fun(char *str)
{
    char p[]= {"VWXYZABCDEFGHIJKLMNOPQRSTU"};
    while(*str)
    {
        int i=0;
        if(*str>='A'&&*str<='Z')
        {
            *(str+i)=*(p+(*(str+i)-'A'));
        }
        i++;
        str++;
    }
    return *str;
}

//理解题意
