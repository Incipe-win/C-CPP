#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int C;
    cin >> C;
    __int64 a[25],b[25];
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    b[0] = 0;
    b[1] = 1;
    b[2] = 1;
    b[3] = 2;
    for (int i = 3; i < 21; i++)
        a[i] = a[i - 1] * i;
    for (int i = 4; i < 21; i++)
        b[i] = (i - 1) * (b[i - 1] + b[i - 2]);
    while (C--) {
        int n, m;
        cin >> n >> m;
        cout << a[n] / a[m] / a[n - m] * b[m] << endl;
    }
    return 0;
}