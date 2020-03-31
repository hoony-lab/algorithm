#include <iostream>
#include <math.h>
#define ll long double
#define MINMAX 1000000
//bool nono[MINMAX + 1];

int main() {
	ll min, max, ans = 0, nono = 0;
	std::cin >> min >> max;


	//for (ll i = sqrt(min); i <= MINMAX; ++i) {

	//	if(i)

	//	for (ll j = min; j <= max; j ^) {

	//	}
	// }

	ans = max - min + 1;

	nono = (floor(sqrt(max)) - ceil(sqrt(min)) + 1);

	//std::cout << ans - nono;
	//std::cout << " min : " << min << '\n';
	//std::cout << " sqrt(min) : " << sqrt(min) << '\n';
	//std::cout << " ceil(sqrt(min)) : " << ceil(sqrt(min)) << '\n';
	
	std::cout << ans - nono;

	return 0;
}