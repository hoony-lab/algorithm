#include <iostream>
#define MIN(x,y) x < y ? x : y
#define FOR(i,n) for(int i = 0; i < n ; ++ i)

int main() {

	int price;
	int min_burger = 1e9, min_beverage = 1e9;

	FOR(i, 5) {
		std::cin >> price;

		if(i < 3)
			min_burger = MIN(min_burger, price);
		else if (i >= 3)
			min_beverage = MIN(min_beverage, price);

	}
	std::cout << min_burger + min_beverage - 50;


	return 0;
}