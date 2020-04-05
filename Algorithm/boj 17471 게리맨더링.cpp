#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define FOR(i, n, k) for(int i = k ; i <= n ; ++i)
int main() {
	std::vector<int> v[11];
	int n, cnt, place, ppl[11], sum = 0;
	std::cin >> n;

	FOR(i, n, 1) {
		std::cin >> ppl[i];
		sum += ppl[i];
	}

	FOR(i, n, 1) {
		std::cin >> cnt;

		FOR(j, cnt, 1) {
			std::cin >> place;
			v[i].push_back(place);
		}
	}

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

	int solo_cnt = 0, group_num = 0, group_cnt = 0;
	FOR(i, n, 1) {
		group_num = visit[i];
		if (visit[i] == 0)
			solo_cnt++;
		if (solo_cnt > 1) {
			std::cout << -1;
			return 0;
		}
		
	}

	while()


	std::cout << -1;

	return 0;
}