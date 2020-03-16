#include <iostream>
#include <queue>
#include <tuple>
#define FOR(i,n,m) for(int i = m ; i < n ; ++i)

//m은 상자 가로칸, n은 상자 세로칸
int m, n, h, time;
int dx[] = { 0,1,0,-1,0,0 };
int dy[] = { 1,0,-1,0,0,0 };
int dl[] = { 0,0,0,0,1,-1 };
int map[101][101][101], visited[101][101][101];

void print(int check[101][101][101]) {
	std::cout << "\ntime " << time << '\n';
	FOR(l, h, 0) {
		FOR(x, n, 0) {
			FOR(y, m, 0) {
				std::cout << check[l][x][y] << " ";
			}std::cout << '\n';
		}std::cout << '\n';
	}
}

int main() {
	std::cin >> m >> n >> h;
	FOR(l, h, 0)	FOR(x, n, 0)	FOR(y, m, 0)	std::cin >> map[l][x][y];

	std::queue<std::tuple<int, int, int>> q;

	FOR(l, h, 0)	FOR(x, n, 0)	FOR(y, m, 0) {
		if (map[l][x][y] != 1) continue;
		q.push(std::make_tuple(l, x, y));
	}

	bool is_tomato = false;
	while (!q.empty()) {
		time++;

		is_tomato = false;
		int qsize = q.size();
		FOR(a, qsize, 0) {
			int tl = std::get<0>(q.front());
			int tx = std::get<1>(q.front());
			int ty = std::get<2>(q.front());
			q.pop();

			FOR(i, 6, 0) {
				int nl = tl + dl[i];
				int nx = tx + dx[i];
				int ny = ty + dy[i];

				if (nl < 0 || nx < 0 || ny < 0 || nl >= h || nx >= n || ny >= m) continue;
				if (map[nl][nx][ny] != 0) continue;

				q.push(std::make_tuple(nl, nx, ny));
				map[nl][nx][ny] = 1;
				is_tomato = true;
			}
		}
		//print(map);
	}


	//완료 검사
	FOR(l, h, 0) {
		FOR(x, n, 0) {
			FOR(y, m, 0) {
				if (map[l][x][y] == 0) {
					std::cout << -1;	return 0;
				}
				if (l == h - 1 && x == n - 1 && y == m - 1) {
					std::cout << time - 1;	return 0;
				}
			}
		}
	}

	return 0;
}
/*
5 3 1
0 -1 0 0 0
-1 -1 0 1 1
0 0 0 1 1

5 3 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0

4 3 2
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
-1 -1 -1 -1
1 1 1 -12
*/