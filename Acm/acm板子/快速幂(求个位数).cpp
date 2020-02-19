/* HDU1061 Rightmost Digit */

#include <iostream>

using namespace std;

// 快速模幂计算函数
int powermod(long long a, int n, int m)
{
    long long res = 1;
    while (n)
    {
        if (n & 1)
        { // n % 2 == 1
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        n >>= 1;
    }
    return res;
}

int main()
{
    int t, n;

    cin >> t;
    while (t--)
    {
        cin >> n;

        cout << powermod(n, n, 10) << endl;
    }
    return 0;
}