#include <iostream>
#include <string>

int main() {
	bool flag = true;
	int ans = 0, temp_num;
	std::string s, temp = "";
	std::cin >> s;
	s += "-";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-' || s[i] == '+') {
			if (flag) {
				ans += std::stoi(temp);
				temp = "";

				if (s[i] == '-') flag = false;
			}
			else {
				ans -= std::stoi(temp);
				temp = "";
			}
		}
		else	temp += s[i];
	}
	std::cout << ans;
}