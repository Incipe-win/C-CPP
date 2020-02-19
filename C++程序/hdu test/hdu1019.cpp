#include <bits/stdc++.h>
using namespace std;

int gcd(int n, int m);
int lcm(int n, int m);
int gcd(int n, int m)
{
    return m > 0 ? gcd(m, n % m) : n;
}
int lcm(int n, int m)
{
    return n / gcd(n, m) * m;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int p, temp = 1, num;
        cin >> p;
        for (int i = 1; i <= p; i++)
        {
            cin >> num;
            temp= lcm(num, temp);
        }
        cout << temp << endl;
    }
    system("pause");
    return 0;
}
