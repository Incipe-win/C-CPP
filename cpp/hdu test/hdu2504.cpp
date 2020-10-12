#include <bits/stdc++.h>

using namespace std;

int gcd(int n, int m);
int gcd(int n, int m)
{
    return m > 0 ? gcd(m, n % m) : n;
}

int main()
{
    int a, b, n;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        for (int i = 2;; i++)
        {
            if (gcd(a, i * b) == b)
            {
                cout << i * b << endl;
                break;
            }
        }
    }
    return 0;
}