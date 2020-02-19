/*#include <iostream>
using namespace std;
int main() {
	int i = 1, sum = 0;
	do {
		sum += i;
		i++;
	} while (i <= 10);
	cout << "sum = " << sum << endl;
	return 0;
}*/

#include <iostream>
using namespace std;
int main() {
	int i = 0, sum = 0;
	for(i=1;i<=10;i++)
	{
		sum += i;
	}
	cout << "sum = " << sum << endl;
	return 0;
}
