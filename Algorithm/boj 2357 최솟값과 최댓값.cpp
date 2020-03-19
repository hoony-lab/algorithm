#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
long long num[100001], dp[100001][100001];
	int n, m;
void check(long long num[]) {
	for (int i = 0; i < n; ++i) std::cout << num[i] << ", ";
	std::cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);	std::cout.tie(NULL);

	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::cin >> num[i];

	}
	
	for (int i = 0; i < m; ++i) {
		long long start, end;
		std::cin >> start >> end;
		////TLE
		//std::set<long long> s;
		//
		//for (int j = start - 1; j < end; ++j) 
		//	s.insert(num[j]);

		//std::cout << *s.begin() << " " << *(--s.end()) << '\n';

	}
		
	return 0;
}