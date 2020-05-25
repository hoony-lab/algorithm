#include <iostream>
#include <queue>
using ll = long long;
int main() {
	ll n, ans = 0, add = 1;
	std::queue<ll> q;

	std::cin >> n;
	while (n) {
		q.push(n % 2);

		n /= 2;
	}

	// 4	100		9 0 0			9
	// 11	1011	27 0 3 1		31

	while (!q.empty()) {
		ans += q.front() * add;
		q.pop();

		add *= 3;
	}

	std::cout << ans;
	return 0;
}

// ref > https://donggod.tistory.com/47