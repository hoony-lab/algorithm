#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define FIO std::ios_base::sync_with_stdio(false), std::cin.tie(NULL);
#define MAX 101
#define FOR(i, n, m) for(int i = m ; i < n ; ++i)
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int map[MAX][MAX], visit[MAX][MAX], melt[MAX][MAX], n, m, time, cheese;
int cnt;

struct pos {
	int x, y;
};

int main() {
	FIO;

	std::cin >> n >> m;
	FOR(x, n, 0) FOR(y, m, 0) std::cin >> map[x][y];

	while (true) {

		std::queue<pos> q;
		memset(visit, 0, sizeof(visit));
		memset(melt, 0, sizeof(melt));

		q.push({ 0,0 });
		visit[0][0] = true;
		cnt = 0;

		while (!q.empty()) {

			int tx = q.front().x;
			int ty = q.front().y;
			q.pop();

			FOR(a, 4, 0) {
				int nx = tx + dx[a];
				int ny = ty + dy[a];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny]) continue;

				visit[nx][ny] = true;

				if (map[nx][ny]) 
					cnt++, melt[nx][ny] = 1;
				else q.push({ nx, ny });
			}
		}

		if (cnt == 0) break;
		cheese = cnt;

		FOR(x, n, 0) FOR(y, m, 0)
			map[x][y] -= melt[x][y];

		time++;
	}

	std::cout << time << '\n' << cheese;

	return 0;
}