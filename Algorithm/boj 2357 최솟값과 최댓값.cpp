#include <iostream>
#include <vector>

long long num[100001];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);	std::cout.tie(NULL);

	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::cin >> num[i];
	}
	for (int i = 0; i < m; ++i) {
		long long start, end, min, max;
		std::cin >> start >> end;



		std::cout << min << " " << max;
	}
		
	return 0;
}