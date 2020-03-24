#include <iostream>
#include <string>
int main() {
	int ans = 0;
	std::string s;
	std::cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		std::cout << s[i] << " : " << (s[i] - 65 + 6) / 3<< '\n';
		ans += (s[i] - 65 + 9) / 3;
		if (s[i] == 'S' || s[i] == 'V' || s[i] == 'Y' || s[i] == 'Z') ans--;
	}
	std::cout << ans;

	return 0;
}
// ABCDEFGHIJKLMNOPQRSTUVWXYZ