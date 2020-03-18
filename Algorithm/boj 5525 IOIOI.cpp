#include <iostream>
#include <vector>
int main() {

	int n, m, ans = 0;
	std::string s;
	std::cin >> n >> m >> s;

	for (int i = 0; i < m; ++i) {
		int count = 0;
		if (s[i] == 'I') {
			bool is_IO = true;
			while (is_IO) {
				
				if (s.substr(i + 1, 2) == "OI") {
					i += 2;
				}

			}
		}
	}
	std::cout << ans;

}