#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <deque>
#define FOR(i, n) for (int i = 0 ; i < n ; ++i)

// R L U D
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

struct Chess {
	int x, y, way;
};

int n, k, temp, ans, map[13][13], upside_down[13], limit = 1000;
std::deque<int> dq[13][13];
std::vector<Chess> v;

void print() {
	FOR(x, n) {
		FOR(y, n) {
			if (dq[x][y].empty())			std::cout << "x";
			else for (auto i : dq[x][y])	std::cout << i;
			std::cout << "\t";
		}std::cout << '\n';
	}std::cout << '\n';
}

int main() {
	std::cin >> n >> k;

	FOR(x, n) FOR(y, n) std::cin >> map[x][y];

	FOR(i, k) {
		int xx, yy, way;
		std::cin >> xx >> yy >> way;

		v.push_back({ xx - 1, yy - 1 , way - 1 });
		dq[xx - 1][yy - 1].push_back(i);
	}

	while (limit--) {
		ans++;

		FOR(i, k) {
			int tx = v[i].x;
			int ty = v[i].y;
			int tway = v[i].way;

			// 맨 아래층 확인
			if (dq[tx][ty].front() != i) continue;

			int nx = tx + dx[tway];
			int ny = ty + dy[tway];

			//std::cout <<ans << " V i : " << i << " << " <<  tx << ", " << ty << " : " << nx << ", " << ny << " :: " << tway <<'\n';

			// 파랑색 혹은 벽
			if (map[nx][ny] == 2 || nx < 0 || ny < 0 || nx >= n || ny >= n) {
				if (tway == 0 || tway == 2)		tway += 1;
				else if(tway == 1 || tway == 3)	tway -= 1;

				nx = tx + dx[tway];
				ny = ty + dy[tway];
				
				v[i].way = tway;

				// 또 파랑색 혹은 벽
				if (map[nx][ny] == 2 || nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			}

			// 이동
			if (map[nx][ny] == 1) {
				while (!dq[tx][ty].empty()) {

					temp = dq[tx][ty].back();
					dq[tx][ty].pop_back();

					dq[nx][ny].push_back(temp);
					v[temp].x = nx;
					v[temp].y = ny;
				}
			}
			else if(map[nx][ny] == 0 /*|| map[nx][ny] == 2*/) {
				while (!dq[tx][ty].empty()) {

					temp = dq[tx][ty].front();
					dq[tx][ty].pop_front();

					dq[nx][ny].push_back(temp);
					v[temp].x = nx;
					v[temp].y = ny;
				}
			}

			// 4개 확인
			int dqsize = dq[nx][ny].size();
			if (dqsize >= 4) {
				std::cout << ans;

				return 0;
			}
			//print();
		}

	}
	if (ans >= 1000) std::cout << -1;

	return 0;
}