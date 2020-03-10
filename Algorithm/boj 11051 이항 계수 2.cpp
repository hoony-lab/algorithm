#include <iostream>

int cache[1002][1002] = { 0, };

long long func(int n, int k) {
	if (k == 0 || n == k) return 1;
	if (cache[n][k] != 0) return cache[n][k];

	cache[n][k] = func(n - 1, k - 1) + func(n - 1, k);

	return cache[n][k] % 10007;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);	std::cout.tie(NULL);

	int n, k;
	std::cin >> n >> k;

	std::cout << func(n, k);

}