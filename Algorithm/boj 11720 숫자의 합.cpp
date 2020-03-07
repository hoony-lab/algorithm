#include <iostream>
#include <string>
#define FOR(i,n) for(int i = 0 ; i < n ; ++i)

int main() {

	int n, ans = 0;
	std::string s;
	std::cin >> n >> s;

	FOR(i, n) ans += s[i] - '0';

	std::cout << ans;

	return 0;
}