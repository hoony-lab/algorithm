#include <iostream>

int num[10001];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);	std::cout.tie(NULL);

	
	int n, max_num = 0;
	std::cin >> n;

	int tmp;
	for (int  i = 0; i < n; i++){
		std::cin >> tmp;
		num[tmp]++;
		max_num < tmp ? max_num = tmp : tmp;
	}

	for (int i = 1; i <= max_num; i++) {
		int size = num[i];
		for (int j = 0; j < size; ++j) {
			std::cout << i << '\n';
		}
	}

}