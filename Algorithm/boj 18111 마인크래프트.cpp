#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <functional>

int map[501][501], block[257];
std::vector<std::pair<int, int>> v;

int main() {
	int n, m, inventory, min_time = 1e9, height = 0;
	std::cin >> n >> m >> inventory;

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m;  ++y) {
			std::cin >> map[x][y];

			block[map[x][y]]++;
		}
	}

	if (inventory)

		//sort(v.begin(), v.end(), [](std::pair<int, int> m1, std::pair<int, int> m2) {
		//	if (m1.second == m2.second) return m1.first < m2.first;
		//	else return m1.second > m2.second;
		//});

		std::cout << min_time << " " << height;
}
/*
2초 블록 제거, 인벤토리 넣기
1초 인벤토리 꺼내기, 블록 놓기

#include<iostream>
using namespace std;

int n, m, b, a[257], result = 1e9, hei, i, j, ret, bb;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	for (cin >> n >> m >> b; i < n*m; i++) {
		cin >> j;
		a[j]++;
	}
	for (i = 256; ~i; i--) {
		ret = 0; bb = b;
		for (j = 256; j > i; j--) {
			ret += a[j] * (j - i) * 2;
			bb += a[j] * (j - i);
		}
		for (j = i - 1; ~j; j--) {
			ret += a[j] * (i - j);
			bb -= a[j] * (i - j);
		}
		if (bb < 0)continue;
		if (result > ret) {
			result = ret;
			hei = i;
		}
	}
	cout << result << ' ' << hei;
}
https://skyde47.tistory.com/62

*/