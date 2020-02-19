#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    getchar();
    while (n--)
    {
        char ch[100017];
        int len, s = 0, e = 0;
        gets(ch);
        len = strlen(ch);
        for (int i = 0; i <len; i++)
        {
            if (ch[i] == ' ')
            {
                e = i;
                reverse(ch + s, ch + e);
                s = e + 1;
            }
        }
        if (ch[len - 1] != ' ')
        {
            e = len;
            reverse(ch + s, ch + e);
        }
        cout << ch << endl;
    }
    return 0;
}