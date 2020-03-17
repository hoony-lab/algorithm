#include <iostream>
#include <string>
#include <vector>
int main() {
	std::string s, bomb;
	std::cin >> s >> bomb;

	//while (1) {
	//	auto where = s.find(bomb);
	//	//std::cout << where << '\n';
	//	if (where > 1000000) break;	
	//	else {

	//	}
	//	s.erase(where, bomb.size());
	//}
	//if (s.empty()) std::cout << "FRULA";
	//else std::cout << s;

	std::vector<std::pair<char, int >> v;

	int cnt = 0;
	int ssize = s.length();
	int bombsize = bomb.length();
	for (int i = 0; i < ssize; ++i) {
		if (s[i] == bomb[0]) cnt = 1;
		else if (s[i] == bomb[cnt]) cnt++;
		else cnt = 0;

		if (cnt == bombsize) {
			for (int i = 0; i < bombsize - 1; ++i) v.pop_back();
			if(!v.empty()) cnt = v.back().second;
		}
		else
			v.push_back(std::make_pair(s[i], cnt));
	}


	if (!v.empty())
		for (std::pair<char, int> p : v) std::cout << p.first;
	else std::cout << "FRULA";
	


}