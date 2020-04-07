#include <iostream>
#include <cstring>
#include <queue>
#define FOR(i, n) for(int i = 0 ; i < n ; ++i)

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
int n, m, t, time = 0, find_sword_time, find_princess_without_sword, swordx, swordy, find_princess, ans = 1e9;
int map[101][101], visit[101][101];
std::queue<std::pair< int, int>> q;

void print(int map[][101], int n, int m) {
	FOR(x, n) { FOR(y, m) { std::cout << map[x][y] << " "; } std::cout << '\n'; } std::cout << '\n';
}

int main() {
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));

	std::cin >> n >> m >> t;
	 
	FOR(x, n) FOR(y, m) {
		std::cin >> map[x][y];
		if (map[x][y] == 2) swordx = x, swordy = y;
	}

	q.push({ 0, 0 });
	visit[0][0] = 0;

	while (!q.empty()) {
		time++;
		
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

				q.push({ nx, ny });
				visit[nx][ny] = visit[tx][ty] + 1;

				//// saved the princess
				if (nx == n - 1 && ny == m - 1) {
					find_princess_without_sword = visit[nx][ny];
					find_princess = true;
					ans = ans < find_princess_without_sword ? ans : find_princess_without_sword;
					break;
				}

				//// find gram sword
				if (map[nx][ny] == 2 && !find_sword_time) {
					find_sword_time = time;
					if (find_sword_time + (n - 1 - swordx) + (m - 1 - swordy) > t) continue;
					ans = ans < find_sword_time + (n - 1 - swordx) + (m - 1 - swordy) ? ans : find_sword_time + (n - 1 - swordx) + (m - 1 - swordy);
				}
				
			}
			if (find_princess) break;
		}
		if (find_princess) break;

		//print(visit, n, m);
	}

	if (ans > t)	std::cout << "Fail";
	else			std::cout << ans;

	return 0;
}
/*

5 5 14
0 1 0 0 0
0 1 2 1 0
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0

6 6 16
0 0 0 0 1 1
0 0 0 0 0 2
1 1 1 0 1 0
0 0 0 0 0 0
0 1 1 1 1 1
0 0 0 0 0 0


7 7 16
0 0 0 0 1 1 0
0 0 0 0 0 2 0
1 1 1 0 1 0 0
0 0 0 0 0 0 0
0 1 1 1 1 1 1
0 0 0 0 0 0 0
0 0 0 0 0 0 0


7 7 24
0 0 0 0 1 1 0
0 0 0 0 0 0 0
1 1 1 1 1 1 0
0 0 0 0 2 0 0
0 1 1 1 1 1 1
0 0 0 0 0 1 0
0 0 0 0 0 1 0
*/