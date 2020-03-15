#include <iostream>
#include <vector>

int main() {
	int n, tmp, sum = 0;
	std::cin >> n;
	std::vector<int> v;
	while (n--) {
		std::cin >> tmp;
		if (!tmp) v.pop_back();
		else v.push_back(tmp);
	}
	for (int num : v) sum += num;

	std::cout << sum;

}