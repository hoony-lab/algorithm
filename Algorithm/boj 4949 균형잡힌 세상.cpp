#include <iostream>
#include <string>
#include <vector>
#define endl '\n'
int main() {

	//char ch;
	//while ((ch = getchar()) !=  '.') {
	//	std::cout << ch;
	//}

	while (1) {
		bool fail = false;
		std::vector<char> v;
		std::string s;
		std::getline(std::cin, s, '\n');
		if (s[0] == '.') return 0;
		//std::cout << s << endl;

		char prev = ' ';
		for (char ch : s) {
			if (ch == ')') {
				if (v.empty() || v.back() != '(') { fail = true; break; }
				v.pop_back();
			}
			else if (ch == '(') v.push_back(ch);

			else if (ch == ']') {
				if(v.empty() || v.back() != '[') { fail = true; break; }
				v.pop_back();
			}
			else if (ch == '[') v.push_back(ch);
		}

		if(fail || !v.empty()) std::cout << "no" << endl;
		else std::cout << "yes" << endl;
	}

}