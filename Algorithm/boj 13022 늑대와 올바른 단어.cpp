#include <iostream>
#include <string>
#define WRONG return !std::cout << 0;

int main() {
	int start = 0;
	std::string s; std::cin >> s;

	if (s[0] != 'w' || s[s.length() - 1] != 'f' || s.length() % 4 != 0) {
		std::cout << 0; return 0;
	}

	while (start < s.length()) {

		int w = s.find('w', start);
		int o = s.find('o', start);
		int l = s.find('l', start);
		int f = s.find('f', start);

		int wo = o - w;
		int ol = l - o;
		int lf = f - l;
		int fw;

		int nextw = s.find('w', f);

		// 마지막 단어
		if (nextw == -1) {
			start = f + wo;
			fw = wo;
		}
		else {
			start = nextw;
			fw = nextw - f;
		}

		if (w >= o || o >= l || l >= f ||
			wo != ol || ol != lf || wo != lf || wo != fw ||
			w < 0 || o < wo || l < wo + ol || f < wo + ol + lf || start < wo + ol + lf + fw) {
			std::cout << 0; return 0;
		}
	}

	std::cout << 1; return 0;
}

/*
wolf
1
wwolfolf
0

//23%

*/