#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, h, i, j;
    while (cin >> n)
    {
        if (!n)
            break;
        char ch[1024][1024];
        int s[1024] = {0};
        h = 0;
        for (i = 0; i < n; i++)
        {
            cin >> ch[i];
        }
        for (i = 0; i < n - 1; i++)
            for (j = i + 1; j < n; j++)
            {
                if (strcmp(ch[i], ch[j]) == 0)
                    s[i]++;
            }
        for (i = 1; i < n; i++)
            if (s[i] > s[h])
                h = i;
        cout << ch[h] << endl;
    }
    return 0;
}