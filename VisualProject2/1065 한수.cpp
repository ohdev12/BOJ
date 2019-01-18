#include <iostream>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	int result;
	if (n < 100) cout << n << endl;
	else {
		result = 99;
		for (int i = 100; i <= n; i++) {
			int a = i % 10;
			int b = i / 10 % 10;
			int c = i / 100;
			if ((c - b) == (b - a)) result++;
		}
		cout << result << endl;
	}
	return 0;
}