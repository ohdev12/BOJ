#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int caseN;
	int x, y;
	int root;
	int n;
	cin >> caseN;
	for (int i = 0; i < caseN; i++) {
		cin >> x >> y;
		n = y - x;
		root = (int)(ceil(sqrt(n)));
		if (n > (root*root) - root)
			cout << (root * 2 - 1) << endl;
		else cout << (root * 2 - 2) << endl;
	}
	return 0;
}