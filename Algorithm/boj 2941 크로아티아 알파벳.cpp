#include <iostream>
#include <string>

int main() {
	int ans = 0, ind = 0;
	std::string s;
	std::cin >> s;
	s.append("  ");

	while (ind < s.size()) {
		//std::cout << "< " << s[ind] << ", ";
		if (s[ind] == 'c' && (s[ind + 1] == '=' || s[ind + 1] == '-')) { ind += 2; }
		else if (s[ind] == 'd') {
			if (s[ind + 1] == '-') { ind += 2; }
			else if (s[ind + 1] == 'z' && s[ind + 2] == '=') {ind += 3; }
			else { ind++; }
		}
		else if (s[ind] == 'l' && s[ind + 1] == 'j') { ind += 2; }
		else if (s[ind] == 'n' && s[ind + 1] == 'j') { ind += 2; }
		else if (s[ind] == 's' && s[ind + 1] == '=') { ind += 2; }
		else if (s[ind] == 'z' && s[ind + 1] == '=') { ind += 2; }
		else if (s[ind] == ' ') break;
		else ind++;
		ans++;
		//std::cout << s[ind-1] << " > ";
	}
	std::cout << ans;

}