#include <iostream>
#include <vector>

int main() {
	int n, temp, answer = 0;

	while (1) {
		std::cin >> n;
		if (n == 0) return 0;

		std::vector<int> v;
		for (int i = 0; i < n; ++i) {
			std::cin >> temp;
			v.push_back(temp);
		}

		int min_height;
		int area;
		std::vector<std::vector<int>> dp;
		for (int start = 0; start < n; ++start) {
			if (v[start] == 0) continue;

			for (int end = start; end < n; ++end) {
				if (v[end] == 0) break;

				min_height = v[start];

				// start ~ end 구간의 최소 높이
				for (int k = start; k <= end; ++k) {
					min_height = min_height < v[k] ?
						min_height : v[k];
				}

				//std::cout << "start : " << i << "end : " << j << " min : " << min_height << '\n';

				area = (end - start + 1) * min_height;

				answer = answer > area ?
					answer : area;

				if (min_height == 1) break;
			}
		}
		std::cout << answer << '\n';
	}
}