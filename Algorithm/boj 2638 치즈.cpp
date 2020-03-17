#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
#define FOR(i,n,m) for(int i = m ; i < n ; ++i)
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int n, m, time;
int map[101][101], map_c[101][101];
std::queue<std::pair<int, int>> q, qair;
int main() {

	time = 0;
	std::cin >> n >> m;
	FOR(x, n, 0)	FOR(y, m, 0) {
		std::cin >> map[x][y];
		if (map[x][y]) q.push(std::make_pair(x, y));
	}


	while (++time) {

		if (q.empty()) {
			std::cout << time - 1;

			return 0;
		}
		int qsize = q.size();

		memset(map_c, 0, sizeof(map_c));
	

		//외부 공기 비접촉 공기 검사
		//가장자리에는 치즈가 놓이지 않는다는 가정
		FOR(x, n, 2)	FOR(y, m, 2) {
			if (map[x][y]) continue;
			qair.push(std::make_pair(x, y));
			map[x][y] = -1;

			while(!qair.empty()) {
				int tx = q.front().first;
				int ty = q.front().second;
				qair.pop();
			
				FOR(a, 4, 0) {
					int nx = tx + dx[a];
					int ny = ty + dy[a];

					if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] != 0) continue;

					qair.push(std::make_pair(nx, ny));
					map[nx][ny] = -1;
				}
			}
		}


		//녹는 치즈 검사
		FOR(i, qsize, 0) {
			int tx = q.front().first;
			int ty = q.front().second;
			q.pop();

			int count = 0;
			FOR(a, 4, 0) {
				int nx = tx + dx[a];
				int ny = ty + dy[a];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] != 0) continue;
				count++;
			}

			if (count >= 2) map_c[tx][ty] += 1;
			else q.push(std::make_pair(tx, ty));
		}

		//치즈 녹이기
		FOR(x, n, 0)	FOR(y, m, 0) {
			if (map_c[x][y]) map[x][y] -= map_c[x][y];
		}
	}


}