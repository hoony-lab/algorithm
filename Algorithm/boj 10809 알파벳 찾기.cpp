#include <iostream>
#include <string>
#define FOR(i,n) for(int i = 0 ; i < n ; ++i)

int main() {

	int alpha[26];
	std::string s;

	FOR(i, 26) alpha[i] = -1;
	std::cin >> s;

	FOR(i, s.size())
		if(alpha[s[i]- (64+32+1)]== -1) alpha[s[i] - (64+32+1)] = i;

	FOR(i, 26) std::cout << alpha[i] << ' ';

	return 0;
}