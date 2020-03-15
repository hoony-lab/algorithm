#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
int main() {
	while (1) {
		int n;
		std::cin >> n;

		std::vector<std::string> v;
		v.push_back(std::to_string(666));

		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {

				if (j == 0) v.push_back(std::to_string(i) +
					std::to_string(666));

				if(j == 0 && i == 0) v.push_back(std::to_string(i) +
					std::to_string(666) +
					std::to_string(j));

				v.push_back(std::to_string(666) +
					std::to_string(j));
			}
		}
		sort(v.begin(), v.end(), std::less<>());

		for(int i = 0; i <= n; ++i) std::cout << v[i] << '\t';
	}

}