#include <iostream>
#include <string>
#define FOR(i,n) for(int i = 0 ; i < n ; ++i)

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);	std::cout.tie(NULL);

	int t;
	std::cin >> t;
	FOR(i, t) {
		int n;
		std::string s;
		std::cin >> n >> s;

		FOR(j, s.size())
			FOR(k, n)
				std::cout << s[j];

		std::cout << '\n';
	}

	return 0;
}