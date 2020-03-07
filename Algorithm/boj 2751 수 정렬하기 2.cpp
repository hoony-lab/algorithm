#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i,n) for(int i = 0 ; i < n ;++i)

int main() {
	int n;
	std::cin >> n;
	std::vector<int> v;

	FOR(i, n) {
		int tmp;
		std::cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	FOR(i, n) std::cout << v[i] << '\n';

	return 0;
}