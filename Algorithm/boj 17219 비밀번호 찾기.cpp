#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::vector<std::pair<std::string,std::string>> v;

	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::string s1, s2;
		std::cin >> s1 >> s2;
		v.push_back(std::make_pair(s1, s2));
	}
	std::sort(v.begin(), v.end());

	//std::cout << "\n\n";
	//for (auto ss : v) std::cout << ss.first << ", " << ss.second << '\n';
	//std::cout << "\n\n";

	for (int i = 0; i < m; ++i) {
		std::string s;
		std::cin >> s;

		int start = 0, end = n-1;
		while (start <= end) {
			int mid = (start + end) / 2;
			//std::cout << start << " ," << mid << " ," << end << '\n';
			if (v[mid].first == s) {
				std::cout << v[mid].second << '\n';	 break;
			}
			else if (v[mid].first > s) end = mid - 1;
			else start = mid + 1;
		}


		//TLE : Time Limit Error
		//int ssize = s.size();
		//for (int j = 0; j < n; ++j) {
		//	/*if (v[j].first == s) {
		//		std::cout << v[j].second << '\n';
		//		break;
		//	}*/
		//}
	}
	

}