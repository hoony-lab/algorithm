#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
#define FOR(i,n,m) for(int i = m ; i < n ; ++i)
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int n, m, time;
int map[101][101], visited[101][101];
std::queue<std::pair<int, int>> qair;

void print(int map[][101]) {
	std::cout << '\n';
	FOR(x, n, 0) {
		FOR(y, m, 0) {
			std::cout << map[x][y] << " ";
		}std::cout << '\n';
	}std::cout << '\n';
}

int main() {

	std::cin >> n >> m;
	FOR(x, n, 0)	FOR(y, m, 0) 
		std::cin >> map[x][y];

	while (++time) {

		//반대로 생각해서 외부 공기 접촉 치즈만 검사 후 제거

		memset(visited, 0, sizeof(visited));

		qair.push(std::make_pair(0, 0));
		visited[0][0] = 1;

		while (!qair.empty()) {
			int tx = qair.front().first;
			int ty = qair.front().second;
			qair.pop();
			
			FOR(a, 4, 0) {
				int nx = tx + dx[a];
				int ny = ty + dy[a];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) continue;

				if (map[nx][ny] == 0) {
					qair.push(std::make_pair(nx, ny));
					visited[nx][ny] = 1;
				}
				else if (map[nx][ny] >= 1) map[nx][ny]++;
			}
		}

		//print(map);

		bool done = true;
		FOR(x, n, 0)	FOR(y, m, 0) {
			if (map[x][y] >= 3)	map[x][y] = 0, done = false;
			else if (map[x][y] == 2) map[x][y] = 1, done = false;
		}

		if (done) {
			std::cout << time - 1; 
			
			return 0;
		}
	}
}

/*

8 9
0 0 0 0 0 0 0 0 0
0 0 0 1 1 0 0 0 0
0 0 0 1 1 0 1 1 0
0 0 1 1 1 1 1 1 0
0 0 1 1 1 1 1 0 0
0 0 1 1 0 1 1 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

*/