#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		__int64 num;
		cin >> num;
		cout << 2 * num * num - num + 1 << endl;
	}
	return 0;
}