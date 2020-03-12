#include <iostream>

int prime[1000001];

int main() {
	int n, m;
	std::cin >> n >> m;

	prime[0] = 0; prime[0] = 1;
	for (int i = 2; i <= m; ++i) {
		prime[i] = 1;
	}

	for (int i = 2; i <= m; ++i) {
		if (!prime[i]) continue;
		for (int j = i * 2; j <= m; j += i) {
			prime[j] = 0;
		}
	}

	for (int i = n; i <= m; ++i) {
		if (prime[i]) std::cout << i << '\n';
	}


}