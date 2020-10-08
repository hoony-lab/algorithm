#include <iostream>
#include <math.h>
#define ld long double
using namespace std;
int main() {
	ld x1, y1, r1, x2, y2, r2, n, ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		ld res = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

		if (x1 == x2 && y1 == y2 && r1 == r2)								cout << -1;
		else if ((x1 == x2 && y1 == y2 && r1 != r2) || res > r1 + r2)		cout << 0;
		else if (res == r1 + r2)											cout << 1;
		else if (res < r1 + r2) {
			if (res > abs(r2 - r1))			cout << 2;
			else if (res == abs(r2 - r1))	cout << 1;
			else if (res < abs(r2 - r1))	cout << 0;
		}
		cout << '\n';
	}
	return 0;
}