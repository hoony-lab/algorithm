#include <iostream>
#include <string>
#define FOR(i,n) for(int i = 0; i < n; ++i)
#define endl '\n'
int main() {
	int n;
	std::cin >> n;

	FOR(i, n) {
		int left = 0, right = 0;
		std::string s, ans = "YES";
		std::cin >> s;


		FOR(i, s.size()) {
			if (s[i] == '(') 
				++left;

			else if (s[i] == ')') {
				++right;
				if (right > left) {
					ans = "NO";
					break;
				}
			}
		}

		if (right != left) ans = "NO";
		std::cout << ans << endl;
	}

}