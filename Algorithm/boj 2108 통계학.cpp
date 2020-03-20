#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX(x,y) x > y ? x : y
float num[500001];
int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) std::cin >> num[i];

	//»ê¼úÆò±Õ
	int sum = 0;
	for (int i = 0; i < n; ++i) sum += num[i];
	std::cout << floor(((float)sum / n) + 0.5) << '\n';

	//Áß¾Ó°ª
	std::sort(num, num + n);
	std::cout << num[n / 2] << '\n';

	//ÃÖºó°ª
	int same_cnt = 0, next_same_cnt = 0, cnt_same_cnt = 0;
	std::map<int, int> m;
	for (int i = 0; i < n; ++i) m[num[i]]++;
	for (int i = 0; i < n; ++i) {
		if (same_cnt < m[num[i]]) {
			same_cnt = m[num[i]];
			cnt_same_cnt = 1;
		}
		else if (same_cnt == m[num[i]]) cnt_same_cnt++;
	}

	if (n == 1) std::cout << num[0] << '\n';
	else if (cnt_same_cnt > 2) {
		int cnt = 0;
		int i;
		for (i = 0; i < n; ++i) {
			//std::cout << "checking < " << num[i] << '\n';

			if (m[num[i]] == same_cnt)
				cnt++;
			if (cnt == same_cnt + 1) {
				std::cout << num[i] << '\n';
				break;
			}
		}
	}
	else std::cout << same_cnt << '\n';

	//¹üÀ§
	std::cout << num[n - 1] - num[0] << '\n';
}