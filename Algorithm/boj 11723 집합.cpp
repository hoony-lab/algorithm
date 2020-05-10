#include <iostream>
#include <set>
#include <string>
#include <sstream>
//#include <istream>
//#include <ostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::set<int> sett;
	std::string s;
	int t, n;

	std::cin >> t;

	while (t--) {

		std::cin >> s;

		if (s == "all") {
			for (int i = 1; i < 21; ++i)
				sett.insert(i);
			continue;
		}
		else if (s == "empty") {
			sett.clear();
			continue;
		}

		std::cin >> n;

		if (s == "add") sett.insert(n);

		else if (s == "check") {
			if (sett.count(n))	std::cout << 1 << '\n';
			else				std::cout << 0 << '\n';
		}

		else if (s == "remove") sett.erase(n);

		else if (s == "toggle") {
			if (sett.count(n))	sett.erase(n);
			else				sett.insert(n);
		}
	}
	return 0;
}