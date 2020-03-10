#include <iostream>
#include <vector>
#define MOD 1000000007

long long fact[4000001], perma[4000001], answer;

long long power(long long x, long long y) {
	long long ret = 1;
	while (y > 0) {
		if (y % 2 == 1) {
			ret *= x;
			ret %= MOD;
		}
		x *= x;
		x %= MOD;
		y /= 2;
	}
	return ret;
}

void factorial(void) {
	fact[1] = 1;
	for (int i = 2; i < 4000001; ++i)
		fact[i] = (fact[i - 1] * i) % MOD;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);	std::cout.tie(NULL);

	int n, k;
	std::cin >> n >> k;

	if (n == k || !k) {
		std::cout << 1;

		return 0;
	}

	factorial();
	perma[4000000] = power(fact[4000000], MOD - 2);

	for (int i = 4000000 - 1; i > 0; --i)
		perma[i] = (perma[i + 1] * (i + 1)) % MOD;

	answer = (fact[n] * perma[n - k]) % MOD;
	answer = (answer * perma[k]) % MOD;

	std::cout << answer;

	return 0;
}

/*
IDK
*/