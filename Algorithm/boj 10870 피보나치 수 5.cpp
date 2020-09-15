#include <iostream>
int fibo(int n) {
	if (n == 1) return 1;
	else if (n == 0) return 0;
	else return fibo(n - 1) + fibo(n - 2);
}
int main() {
	int t; std::cin >> t;
	std::cout << fibo(t);
	return 0;
}