#include <iostream>
#include <set>
#include <string>
int main() {
	std::set<int> sett;
	std::string s1, s2;
	int t, n;
	std::cin >> t; getchar();
	while (t--) {

		std::getline(std::cin, s1, ' ');
		if (s1 == "all") {
			for (int i = 1; i < 21; ++i)
				sett.insert(i);
			continue;
		}
		else if (s1 == "empty") {
			sett.clear();
			continue;
		}

		std::getline(std::cin, s2, '\n');
		n = std::stoi(s2);
		
		std::cout << s1.length() << ", " << s2.length() << '\n';


		if (s1 == "add") sett.insert(n);

		else if (s1 == "check") {
			if (sett.count(n))	std::cout << 1 << '\n';
			else				std::cout << 0 << '\n';
		}

		else if (s1 == "remove") sett.erase(n);

		else if (s1 == "toggle") {
			if (sett.count(n))	sett.erase(n);
			else				sett.insert(n);
		}



		
	}

	return 0;
}