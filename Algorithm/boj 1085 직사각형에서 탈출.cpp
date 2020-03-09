#include <iostream>

int main() {
	int x, y, w, h, ans;
	std::cin >> x >> y >> w >> h;

	int min_y = abs(h - y) < y ? abs(h - y) : y;
	int min_x = abs(w - x) < x ? abs(w - x) : x;

	ans = min_x < min_y ? min_x : min_y;
	std::cout << ans;

}