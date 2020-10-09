#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int n, m, num, k = 1;
        while (cin >> n >> m)
        {
            if (n == 0 && m == 0)
                break;
            num = 0;
            for (int i = 1; i < n; i++)
                for (int j = i + 1; j < n; j++)
                {
                    if ((i * i + j * j + m) % (i * j) == 0)
                        num++;
                }
            cout << "Case"
                 << " " << k++ << ":"
                 << " " << num << endl;
        }
        if (N)
            cout << endl;
    }
    return 0;
}