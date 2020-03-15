#include <iostream>

int main() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; ++i) {
		int num = i;
		int sum = num;

		while (num > 0) {
			sum += num % 10;
			num = num / 10;
		}

		//std::cout << i << ", " << sum << '\n';

		if (sum == n) {
			std::cout << i; 

			return 0;
		}
	}
	
	std::cout << 0;

}