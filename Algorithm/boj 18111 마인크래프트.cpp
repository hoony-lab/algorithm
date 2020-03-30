#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <functional>
#define ll long long

int map[501][501], block[257];
std::set < ll> se;
std::map<ll, ll> ma;
int main() {
	int n, m, inventory, max_height = 0, min_height = 1e9, max_block = 0;
	int max_count = 0, answer = 0;
	std::cin >> n >> m >> inventory;

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			std::cin >> map[x][y];

			//block[map[x][y]]++;
			ma[map[x][y]]++;

			if (max_count < ma[map[x][y]]) {
				max_count = ma[map[x][y]];
				max_block = map[x][y];
			}
			if (map[x][y] > max_height) max_height = map[x][y];
			if (map[x][y] < min_height) min_height = map[x][y];
		}
	}

	//std::cout << "max : " << max_height << " || " << "min : " << min_height << '\n';
	//std::cout << "block[max] : " << block[max_height] << " || " << "block[min] : " << block[min_height] << '\n';

	bool fail = false;

	for (int x = 0; x < n && !fail; ++x) {
		for (int y = 0; y < m; ++y) {
			if (map[x][y] == max_block) continue;

			int diff = map[x][y] - max_block;

			if (diff > 0)
				answer += abs(diff) * 2;
			else {
				answer += abs(diff);
				inventory--;
				if (inventory < 0) {
					fail = true;
					break;
				}
			}
		}
	}


	if (fail) {
		answer = 0;

		for (int x = 0; x < n; ++x) {
			for (int y = 0; y < m; ++y) {
				int diff = map[x][y] - min_height;

				answer += (abs(diff) * 2);
			}
		}

		std::cout << answer << " " << min_height;
	}
	else {
		std::cout << answer << " " << max_block;
	}
	return 0;
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