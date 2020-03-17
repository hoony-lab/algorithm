#include <iostream>
#include <algorithm>
#include <string>

int main() {

	while (1) {
		std::string s;
		std::cin >> s;
		if (s == "0") return 0;

		std::string ans = "no", start, end;
		int len = s.length();

		start = s.substr(0, len / 2);
		std::reverse(s.begin(), s.end());
		end = s.substr(0, len / 2);

		//std::cout << start << ", " << end << '\n';

		if (start.compare(end) == 0) ans = "yes";

		std::cout << ans << '\n';
	}

}