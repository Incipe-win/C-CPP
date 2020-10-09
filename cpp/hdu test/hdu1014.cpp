#include <bits/stdc++.h>
using namespace std;
int gcd(int n, int m);
int gcd(int n, int m)
{
    return m > 0 ? gcd(m, n % m) : n;
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << setw(10) << a << setw(10) << b << "    ";
        if (gcd(a, b) == 1)
            cout << "Good Choice" << endl;
        else
            cout << "Bad Choice" << endl;
        cout<<endl;
    }
    return 0;
}