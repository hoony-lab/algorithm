#include <iostream>
using namespace std;

int dd[100000];

int d(int n) {
	cout << n << " : ";
	int sum = n;
	while (n > 0) {
		cout << n % 10 << ", ";
		sum += n % 10;
		n /= 10;
	}
	cout << " :: " << sum << '\n';
	return sum;
}

int main() {
	int n = 1;

	while(d(n) < 20000){
		dd[d(n)] = true;
		n++;
	}
	cout << "\n\n";
	for (int i = 1; i < 10001; ++i) {
		if (!dd[i]) cout << i << '\n';
	}

	return 0;
}