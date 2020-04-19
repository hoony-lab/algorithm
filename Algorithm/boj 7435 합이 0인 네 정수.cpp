#include <iostream>
#include <algorithm>
typedef long long ll;

int main() {
	ll num[4][4001], n;

	std::cin >> n;
	for (int i = 0; i < n; i++) 
		for (int a = 0; a < 4; a++) 
			std::cin >> num[a][i];

	for (int a = 0; a < 4; a++) 
		std::sort(num[a], num[a] + n);
	
	
	std::cout << "\n\n";
	for (int a = 0; a < 4; a++) {
		for (int i = 0; i < n; i++) {
			std::cout << num[a][i] << " ";
		}std::cout << '\n';
	}


	return 0;
}