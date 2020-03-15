#include <iostream>
#include <algorithm>

#define MAX(x,y) x > y ? x : y
float num[500001], ans[4], max_cnt_num[2];
int main() {
	int n, max_cnt = 0, next_max_cnt = 0, cnt = 0, same_max_cnt = 0;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		std::cin >> num[i], ans[0] += num[i];
		if (!i) continue;

		if (num[i] == num[i - 1]) cnt++;
		else {
			if (max_cnt < cnt) {
				next_max_cnt = max_cnt;
				max_cnt = cnt;
				same_max_cnt = 0;

				max_cnt_num[0] = num[i - 1];
			}
			else if (max_cnt == cnt) {
				same_max_cnt++;
				if (cnt < 2) 
					max_cnt_num[1] = num[i-1];
			}
			cnt = 1;
		}
	}

	std::count(num, num + n, 30);
	std::sort(num, num + n);
	ans[0] = floor((ans[0] / n) + 0.5);
	ans[1] = num[n / 2];

	if (max_cnt == 1) ans[2] = num[1];
	else if (same_max_cnt) max_cnt_num[0] < max_cnt_num[1] ? 
		ans[2] = max_cnt_num[1] : ans[2] = max_cnt_num[0];
	else ans[2] = max_cnt;
	if (n == 1) ans[2] = num[0];

	ans[3] = num[n - 1] - num[0];





	for (int i = 0; i < 4; ++i) std::cout << ans[i] << '\n';

}