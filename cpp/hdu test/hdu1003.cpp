#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        int n, num, sum = -1001, temp = -1001, a, b, A, B;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> num;
            if (sum + num < num)
            {
                sum = num;
                a = b = i;
            }
            else
            {
                sum += num;
                ++b;
            }
            if (temp < sum)
            {
                temp = sum;
                A = a;
                B = b;
            }
        }
        cout << "Case"
             << " " << j << ":" << endl;
        cout << temp << " " << A << " " << B << endl;
        if (j - t)
            cout << endl;
    }
    system("pause");
    return 0;
}