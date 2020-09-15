#include <iostream>
#define F(i, n) for(int i = 1 ; i <= n ; ++i)
int fac(int n) {
	int ans = 1; F(i, n) ans *= i; return ans;
}
int main() {
	int t; std::cin >> t;
	std::cout << fac(t);
	return 0;
}
