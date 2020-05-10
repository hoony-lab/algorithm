#include <iostream>
#include <string>
//#include <cstring>

int main() {
	int t, n; std::cin >> t;
	while (t--) {
		std::cin >> n;
		if (!n) {}
		else {
			
			char* ss;
			std::string s = "asd";
			strcpy(ss, &s[0]);
			s.copy(ss, s.size() + 1);
			strtok(s.c_str() , " -,.");

		}
	}
	return 0;
}