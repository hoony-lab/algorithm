#include <iostream>
#define MAX(x,y) x > y ? x : y
#define MIN(x,y) x < y ? x : y
int main() {

	while (1) {
		bool possible = false;
		int a, b, c;
		std::cin >> a >> b >> c;
		if (!a && !b && !c) break;

		if (MAX(a, b) == a) {
			if (MAX(a, c) == a) {
				if (a*a == b * b + c * c) possible = true;
			}
			else
				if (c*c == a * a + b * b) possible = true;
		}
		else {
			if (MAX(b, c) == b) {
				if (b*b == a * a + c * c) possible = true;
			}
			else
				if (c*c == a * a + b * b) possible = true;
		}

		if (possible) std::cout << "right\n";
		else std::cout << "wrong\n";
	}

}