#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i = 0 ; i< n; ++i)
int main() {
	int n, rank = 1;
	std::cin >> n;

	std::vector<std::pair<int, int>> v;

	FOR(i, n) {
		int x, y;
		std::cin >> x >> y;
		v.push_back(std::make_pair(x, y));
	}

	FOR(i, n) {
		FOR(j, n)
			if (v[i].first < v[j].first && v[i].second < v[j].second) rank++;
		std::cout << rank << " ";
		rank = 1;
	}

	//sort(v.begin(), v.end(), [](std::pair<int, int> v1, std::pair<int, int> v2) {
	//	if (v1.first == v2.first)
	//		return v1.second < v2.second;
	//	else return v1.first < v2.first;
	//});

	//sort(v3.begin(), v3.end(), [](std::pair<int, int> v1, std::pair<int, int> v2) {
	//	if (v1.second == v2.second)
	//		return v1.first < v2.first;
	//	else return v1.second < v2.second;
	//});

	//FOR(i, n) {
	//	std::cout << v[i].first << " " << v[i].second << endl;
	//}

	//std::cout << endl;

	//FOR(i, n) {
	//	std::cout << v3[i].first << " " << v3[i].second << endl;
	//}

}