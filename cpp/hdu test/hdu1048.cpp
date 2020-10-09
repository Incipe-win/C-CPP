#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[120], ss[10005], b[100] = {"VWXYZABCDEFGHIJKLMNOPQRSTU"};
    while (gets(s) != NULL)
    {
        if (strcmp(s, "ENDOFINPUT") == 0)
            break;
        else if (strcmp(s, "START") == 0)
        {
            gets(ss);
            char *p;
            p = ss;
            while (*p)
            {
                if (*p >= 'A' && *p <= 'Z')
                    *p = b[*p - 'A'];
                p++;
            }
            gets(s);
        }
        puts(ss);
    }
    return 0;
}