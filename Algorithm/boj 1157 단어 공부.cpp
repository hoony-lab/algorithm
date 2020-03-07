#include <iostream>
#include <string>
#define FOR(i,n) for(int i = 0 ; i < n ; ++i)
#define MIN(x,y) x < y ? x : y
#define MAX(x,y) x > y ? x : y
int main() {

	int alpha[26] = { 0, }, max_alpha_cnt = 0, same = 0, ans;
	std::string s;
	std::cin >> s;

	FOR(i, s.size()) {
		s[i] = toupper(s[i]);
		alpha[(s[i]) - 65]++;
		max_alpha_cnt = MAX(max_alpha_cnt, alpha[s[i] - 65]);
	}

	FOR(i, 26) {
		if (max_alpha_cnt == alpha[i]) {
			same++;
			ans = i;
		}
	}
		
	if (same > 1) std::cout << '?';
	else std::cout << char('A' + ans);

	return 0;
}