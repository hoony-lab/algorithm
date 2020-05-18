#include <iostream>
#include <vector>
#include <algorithm>
//#define NANO 10'000'000
using vi = std::vector<int>;
int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int x;
	while (scanf_s("%d", &x) == 1) {
		vi v;
		x *= 10000000;

		bool done = false;
		int t; std::cin >> t; 
		while (t--) {
			int n;	std::cin >> n;	v.push_back(n);
		}

		std::sort(v.begin(), v.end());

		for (int i = 0; i < v.size() - 1; ++i) {
			int match = std::upper_bound(v.begin(), v.end(), x - v[i]) - v.begin() - 1;

			if (v[match] + v[i] != x) continue;

			std::cout << "yes " << v[i] << " " << v[match] << '\n';
			done = true; 
			break;
		}
		if (done) continue;
		std::cout << "danger\n";
	}
	return 0;
}