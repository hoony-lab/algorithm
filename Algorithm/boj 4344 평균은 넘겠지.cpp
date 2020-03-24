#include <iostream>
#include <vector>
#include <iomanip>
int main() {
	int t;
	std::cin >> t;
	while (t--) {
		float n, tmp, sum=0, cnt=0;
		
		std::cin >> n;
		std::vector<int> v;
		for (int i = 0; i < n; i++) {
			std::cin >> tmp;
			sum += tmp;
			v.push_back(tmp);
		}
		sum /= n;

		for(int i = 0 ; i < n; i++) 
			if (v[i] > sum) cnt++;
		
		printf("%.3f", 100 * cnt / n );
		printf("%\n");
	}

	return 0;
}