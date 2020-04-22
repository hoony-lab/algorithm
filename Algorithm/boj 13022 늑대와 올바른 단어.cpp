#include <iostream>
#include <string>
#define W 0
#define O 1
#define L 2
#define F 3
int ans, wolf[4], flag;

int main() {
	std::string s; std::cin >> s;

	for (int i = 0; i < s.size(); ++i) {

		if (i && s[i - 1] == 'f' && s[i] != 'w') {
			if (flag) {
				flag = false;
				for (int a = 1; a < 4; ++a)
					if (wolf[a - 1] != wolf[a]) return !std::cout << 0;

			}
		}
		else if (s[i] == 'w') wolf[W]++;
		else if (s[i] == 'o') wolf[O]++;
		else if (s[i] == 'l') wolf[L]++;
		else if (s[i] == 'f') wolf[F]++, flag = true;


		//else if (s[i] == 'o') 
		//	if (wolf[W] > wolf[O]) wolf[O]++; 
		//	else return !std::cout << 0;

		//else if (s[i] == 'l')
		//	if (wolf[O] > wolf[W]) wolf[L]++;
		//	else return !std::cout << 0;

		//else if (s[i] == 'f')
		//	if (wolf[L] > wolf[F]) wolf[F]++; 
		//	else return !std::cout << 0;
	}

	std::cout << 1;
	return 0;
}