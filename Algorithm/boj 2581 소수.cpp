#include <iostream>
#define MAX 100000
int main() {

	int prime[MAX] = { 0, };
	for (int i = 2; i < MAX; ++i)
		prime[i] = 1;

	for (int i = 2; i < MAX; ++i) {
		if (!prime[i]) continue;
		for (int j = i * 2; j < MAX; j += i)
		{
			prime[j] = 0;
		}
	}
	bool first = true;
	int n, m, sum = 0, ans;
	std::cin >> n >> m;
	for (int i = n; i <= m; ++i) {
		if (prime[i]) {
			sum += i;
			if (first) { ans = i; first = false;  }
		}
	}
	if (first) std::cout << "-1";
	else std::cout << sum << "\n" << ans;
}