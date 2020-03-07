#include <iostream>
#define FOR(i,n) for(int i = 0 ; i < n ; ++i)
int main() {

	int n, sum=0;
	FOR(i, 5) {
		std::cin >> n;
		n *= n;
		sum += n;
	}
	std::cout << sum % 10;
	return 0;
}