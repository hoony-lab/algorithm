#include <iostream>
#include <vector>
#include <string>
int main() {

	int n, m, ans = 0;
	std::string s;
	std::cin >> n >> m >> s;

	int ind = 0;
	while (ind <= m) {

		int count = 0;
		if (s[ind] == 'I') {
			//std::cout << "check : I : " << ind << '\n';
			++ind;

			bool is_IO = true;
			while (is_IO) {

				if (s.substr(ind, 2) == "OI") {
					ind += 2;
					count++;
					//std::cout << "ind : " << ind << '\n';
				}
				else is_IO = false;

			}
			if (count >= n) ans += count - n + 1;
		}
		else ind++;

	}
	std::cout << ans;

}