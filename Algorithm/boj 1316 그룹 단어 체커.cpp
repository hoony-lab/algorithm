#include <iostream>
#include <string>
#include <map>
int main() {
	int t, ans = 0;
	std::cin >> t;
	while (t--) {
		bool groupWord = true;
		std::map <char, int> m;
		std::string s;
		std::cin >> s;

		m[s[0]]++;
		for (int i = 1; i < s.size(); ++i) {

			if(m[s[i]] == 0 || s[i] == s[i - 1]) m[s[i]]++;
			else {
				groupWord = false;
				break;
			}
		}

		if (groupWord) ans++;
		
	}
	std::cout << ans;

	return 0;
}