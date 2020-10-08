#include <iostream>
using namespace std;
#define ll long long
int main() {
	ll n, l; cin >> n >> l;
	for (int i = l; i < 101; i++) {
		int temp = n - i * (i + 1) / 2;

		if (temp % i == 0) {
			int j = temp / i + 1;

			if (j >= 0) {
				for (int k = 0; k < i; k++) {
					cout << k + j << " ";
				}
				cout << "\n";
				return 0; 
			}
		}
	} cout << -1 << "\n";
}