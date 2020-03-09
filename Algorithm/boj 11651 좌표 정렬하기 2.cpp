#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i,n) for(int i = 0 ; i < n ; ++i)
#define endl '\n'
int main() {

	int n, x, y;
	std::vector<std::pair<int, int>> v;
	std::cin >> n;

	FOR(i, n) {
		std::cin >> x >> y;
		v.push_back(std::make_pair(x, y));
	}

	sort(v.begin(), v.end(), [](std::pair<int, int> v1, std::pair<int, int> v2) {
		if (v1.second == v2.second) return v1.first < v2.first;
		else return v1.second < v2.second;
	});

	FOR(i, n) {
		std::cout << v[i].first << " " << v[i].second << endl;
	}

}