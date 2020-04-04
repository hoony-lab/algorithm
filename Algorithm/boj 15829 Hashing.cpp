#include <iostream>
#include <string>
#define ll long long
int main() {
	ll r = 31, M = 1234567891, n, ans = 0, temp;
	std::string s;
	std::cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		temp = s[i] - '`';			// s[i] - 96

		for (int k = 0; k < i; ++k) {
			temp *= 31;
			temp %= M;
		}

		ans += temp;
		ans %= M;
	}
	std::cout << ans;
		
}