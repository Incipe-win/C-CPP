#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n, sum;
    while (cin >> n)
    {
        if (!n)
            break;
        sum = 0.0;
        int count = 0;
        for (int i = 1;; i++)
        {
            sum += (double)1 / (i + 1);
            count++;
            if (sum >= n)
                break;
        }
        cout << count << " "
             << "card(s)" << endl;
    }
    return 0;
}