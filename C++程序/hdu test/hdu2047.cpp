#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long ans[45];
	ans[1] = 3;
	ans[2] = 8;
	for (int i = 3; i < 40; i++) {
		ans[i] = 2 * (ans[i-2] + ans[i - 1]);
	}
	while (cin >> n){
		cout << ans[n] << endl;
	}
	return 0;
}