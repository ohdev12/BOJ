#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int x1, y1, r1, x2, y2, r2, caseN, rDiff, rSum, result;
	double d;
	cin >> caseN;
	while (caseN--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		rDiff = (r1 > r2) ? r1 - r2 : r2 - r1;
		rSum = r1 + r2;
		if (rSum < d) result = 0;
		else if (rSum == d) result = 1;
		else if (rDiff < d) result = 2;
		else if (rDiff == d) {
			if (rDiff == 0) result = -1;
			else result = 1;
		}
		else result = 0;
		cout << result << endl;
	}
	return 0;
}