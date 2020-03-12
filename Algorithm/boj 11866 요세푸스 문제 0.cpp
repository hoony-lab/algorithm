#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void print(std::vector<int> v, int n) {
	std::cout << "<";
	for (int i = 0; i < n - 1; ++i)std::cout << v[i] << ", ";
	std::cout << v[n - 1] << ">";
}

int main() {
	std::vector<int> v, ans;
	std::vector<int>::iterator low, up;
	int n, k, ind = 0;
	std::cin >> n >> k;

	for (int i = 1; i <= n; ++i) v.push_back(i);

	while (v.size()) {
		ind += k - 1;
		ind %= v.size();

		ans.push_back(v[ind]);
		v.erase(v.begin() + ind);
	}
	print(ans, n);

}
/*
123456712 / 345671234567
  3  6  2  5  1  4  7

1234567
12 4567	3
12 45 7	6
1  45 7	2
1  45	7
1  4	5
   4	1
		4
*/