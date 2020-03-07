#include <iostream>
#define FOR(i,n) for(int i = 0 ; i < n ; ++i)

int main() {
	int n[9], max=0, max_ind;

	FOR(i, 9) {
		std::cin >> n[i];
		if (n[i] > max) {
			max = n[i];
			max_ind = i;
		}
	}

	std::cout << max << '\n' << max_ind + 1;

	return 0;
}