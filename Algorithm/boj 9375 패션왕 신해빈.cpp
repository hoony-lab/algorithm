#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
	std::ios_base::sync_with_stdio(false);		std::cin.tie(NULL);

	int t;
	std::cin >> t;
	while (t--) {
		std::map < std::string, int> m;
		std::string s[2];
		int n, ans = 1;
		std::cin >> n;

		for (int i = 0; i < n; ++i) {
			std::cin >> s[0] >> s[1];
			m[s[1]]++;
		}

		for (std::pair<std::string, int> p : m) 
			ans *= p.second + 1;

		std::cout << ans - 1 << '\n';
	}
	
}