#include <iostream>
#define ll long long
int main() {
	ll n, ans = 0;
	std::cin >> n;
	for (int i = 5; i <= n; i *= 5)
		ans += n / i;

	std::cout << ans;
	return 0;
}