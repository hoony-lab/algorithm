#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define FOR(i, n, k) for(int i = k ; i <= n ; ++i)

std::vector<int> v[11];
int n, cnt, place, ppl[11];


void bfs(int select[]) {
	// check if its rotatable

	std::queue<int> q;
	int visit[11] = { 0, };

	FOR(i, n, 1) {
		if (v[i].empty || visit[i]) continue;
		q.push(i);
		visit[i] = i;

		while (!q.empty()) {
			place = q.front();
			q.pop();





			FOR(j, v[place].size() - 1, 0) {
				q.push(v[place][j]);
				visit[v[place][j]] = i;
			}
		}
	}
}

void section() {

	// 15 24 33 (42 51)
	// 100000 010000 ...
	int select[11];


	FOR(i, n / 2, 1) {

		FOR(j, i, 1) select[i] = 1;
		FOR(j, n, i) select[i] = 0;

		do {
			bfs(select);
		} while (std::next_permutation(select, select + n));
	}
}

void solve() {

	section();

}

void init() {

	std::cin >> n;

	FOR(i, n, 1) std::cin >> ppl[i];

	FOR(i, n, 1) {
		std::cin >> cnt;

		FOR(j, cnt, 1) {
			std::cin >> place;
			v[i].push_back(place);
		}
	}
}
int main() {

	init();
	solve();

	return 0;
}