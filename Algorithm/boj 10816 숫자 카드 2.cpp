#include <iostream>
#include <algorithm>
#include <vector>

//int n[500001];
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);	std::cout.tie(NULL);
	int n, m, tmp; 
	std::vector<int> v1;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
		//std::cin >> n1[i];
		std::cin >> tmp, v1.push_back(tmp);

	//std::sort(n1, n1 + n);
	std::sort(v1.begin(), v1.end());
	std::vector<int>::iterator low, up;

	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		int ans = 0;
		std::cin >> tmp;

		low = std::lower_bound(v1.begin(), v1.end(), tmp);
		up = std::upper_bound(v1.begin(), v1.end(), tmp);

		//for (int j = 0; j < n; ++j) {
		//	//if (n1[j] == tmp) ans++;
		//	if (v1[j] == tmp) ans++;
		//	else if (ans) break;
		//}

		std::cout << up - low << ' ';
	}

}