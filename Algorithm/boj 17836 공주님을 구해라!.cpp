#include <iostream>
#include <cstring>
#include <queue>
#define FOR(i, n) for(int i = 0 ; i < n ; ++i)

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
int n, m, t, time = 0;
int map[101][101], visit[101][101];
std::queue<std::pair< int, int>> q;

void print(int map[][101], int n, int m) {
	FOR(x, n) { FOR(y, m) { std::cout << map[x][y] << " "; } std::cout << '\n'; } std::cout << '\n';
}
int main() {
	std::cin >> n >> m >> t;
	FOR(x, n) FOR(y, m) std::cin >> map[x][y];

	q.push({ 0, 0 });
	visit[0][0] = true;

	while (!q.empty()) {
		time++;
		if (time > t) {
			std::cout << "Fail";
			return 0;
		}
		//std::cout << " @ time : " << time << '\n';

		int qsize = q.size();
		FOR(i, qsize) {
			int tx = q.front().first;
			int ty = q.front().second;
			q.pop();

			FOR(a, 4) {
				int nx = tx + dx[a];
				int ny = ty + dy[a];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny] || map[nx][ny] == 1) continue;
				//std::cout << nx << " " << ny << " " << tz << '\n';

				//// saved the princess, answer
				if (nx == n - 1 && ny == m - 1) {
					std::cout << time;
					return 0;
				}

				if (map[nx][ny] == 0) {
					q.push({ nx, ny });
					visit[nx][ny] = visit[tx][ty] + 1;
				}
				//// find gram sword
				else if (map[nx][ny] == 2) {
					//// cannot reach the princess, Fail
					if (time + (n - 1 - nx) + (m - 1 - ny) > t) std::cout << "Fail";
					else std::cout << time + (n - 1 - nx) + (m - 1 - ny);
					return 0;
				}
			}
			//// timeover, Fail
			
			
		}
		//std::cout << "print \n";
		//print(visit, n, m, 0);
		//std::cout << "\n";
		//print(visit, n, m, 1);
	}
	//// cannot reach the princess, Fail
	if (!visit[n - 1][m - 1] || !visit[n - 1][m - 1] || time > t)
		std::cout << "Fail";

	return 0;
}