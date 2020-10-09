#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, i, j;
    while (cin >> a >> b)
    {
        i = a;
        j = b;
        if (i > j)
        {
            i ^= j;
            j ^= i;
            i ^= j;
        }
        int n = 0, temp, max = 0;
        for (int k = i; k <= j; k++)
        {
            int m = k;
            temp = 1;
            while (m != 1)
            {
                if (m % 2 == 0)
                    m = m / 2;
                else
                    m = 3 * m + 1;
                temp++;
            }
            if (temp > max)
                max = temp;
        }
        cout << a << " " << b << " " << max << endl;
    }
    return 0;
}