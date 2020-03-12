#include <iostream>
#include <iomanip>
int main() {
	int t;
	std::cin >> t;

	while (t--) {
		int h, w, n;
		std::cin >> h >> w >> n;

		int floorh = n % h;
		int roomw = n / h + 1;

		if (!floorh) {
			floorh = h;
			roomw -= 1;
		}
		//setfill(0) << setw(2);
		std::cout << floorh;
		if (roomw >= 10) std::cout << roomw << '\n';
		else std::cout << 0 << roomw << '\n';
	}

}

/*
3
6 12 12
6 12 10
30 50 72
*/