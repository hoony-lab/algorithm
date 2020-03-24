#include <iostream>

int main() {
	int a, b, c, t;
	std::cin >> a >> b >> c;
	if (b >= c) { std::cout << -1; return 0; }
	
	t = a / (c  - b) + 1;

	std::cout << t;

	return 0;
}