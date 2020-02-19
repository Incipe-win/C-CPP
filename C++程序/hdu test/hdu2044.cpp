#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, b;
	cin >> n;
	while (n--)
	{
		__int64 ans[55];
		cin >> a >> b;
		ans[0] = 0;
		ans[1] = 0;
		ans[2] = 1;
		ans[3] = 2;
		for (int i = 4; i <= b - a + 1; i++)
			ans[i] = ans[i - 1] + ans[i - 2];
		cout << ans[b - a + 1] << endl;
	}
	return 0;
}