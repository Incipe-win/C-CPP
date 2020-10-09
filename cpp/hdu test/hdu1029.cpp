#include <bits/stdc++.h>
using namespace std;
const int N = 1000009;
int s[N];
int main()
{
    int n;
    while (cin >> n)
    {
        int count, temp;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < n; i++)
        {
            count = 0;
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                    count++;
            }
            if (count >= (n + 1) / 2)
            {
                temp = s[i];
                break;
            }
        }
        cout << temp << endl;
    }
    return 0;
}