#include <iostream>

int main() {
	int n, m, greatest_common_measure, least_common_multiple;
	std::cin >> n >> m;
	if (n == m) {
		std::cout << n << '\n' << n;
		return 0;
	}

	int firstn = n;
	int firstm = m;

	while (1) {
		if (n > m) {
			n = n - m % (n * (n / m));
			if (m % n == 0) break;
		}
		else {
			m = m - n % (m * (m / n));
			if (n % m == 0) break;
		}
	}

	if (n < m) std::cout << n << '\n' << (firstm / n) * (firstn);
	else std::cout << m << '\n' << (firstm) * (firstn / m);
}
/*
20 8	20-8*2 = 4

22 8	22-8*2 = 6		8 6		8-6 = 2
*/