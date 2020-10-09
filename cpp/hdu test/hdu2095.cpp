#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	while (cin >> n) {
		if (n == 0)break;
		int s = 0, a;
		while (n--) {
			cin >> a;
			s ^= a;
		}
		cout << s << endl;
	}
	return 0;
}