// 20200516 10:55 ~ 11:42
#include <iostream>
#include <queue>
#include <math.h>
#define F(i, n) for (int i = 0 ; i < n ; ++i)
#define MAX 51
struct P { int x, y, t; };
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1,0,-1,0 };
int n, m, max_time, ans, min_time;
char map[MAX][MAX];
void print(int map[][MAX]) {
	F(x, n) { F(y, m) { std::cout << map[x][y]; } std::cout << '\n'; }
	std::cout << "\n\n";
}
int main() {
	std::cin >> n >> m;
	F(x, n) F(y, m) std::cin >> map[x][y];

	F(x, n) F(y, m) {
		if (map[x][y] == 'W') continue;

		int visit[MAX][MAX]{}; visit[x][y] = 1;
		std::queue<P> q; q.push({ x, y });

		int time = 1e9;

		while (!q.empty()) {
			int tx = q.front().x, ty = q.front().y, tt = q.front().t;
			q.pop();

			F(a, 4) {
				int nx = tx + dx[a], ny = ty + dy[a];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 'W' || visit[nx][ny]) continue;

				visit[nx][ny] = visit[tx][ty] + 1;
				q.push({ nx,ny });
				min_time = visit[nx][ny] < time ? visit[nx][ny] : time;
			}
		}
		// 최단 시간
		ans = ans > min_time ? ans : min_time;

		//std::cout << x << ", " << y <<  " :: " << ans << " :: " << '\n';
		//print(visit);
	}
	std::cout << ans - 1;
	return 0;
}