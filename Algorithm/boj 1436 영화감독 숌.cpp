#include <iostream>

int main() {
	int n, cnt = 0, ans = 665, tmp_ans, isTripleSix;
	std::cin >> n;
	while (n != cnt) {
		ans++;
		tmp_ans = ans;

		isTripleSix = false;
		while (tmp_ans != 0) {
			if (tmp_ans % 1000 == 666) isTripleSix = true;
			tmp_ans /= 10;
		}
		if (isTripleSix) cnt++;
	}
	std::cout << ans;
}