#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MA(a, b) a > b ? a : b
#define MAX 51

// W N E S
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

struct pos {
	int x, y;
};

int n, m, map[MAX][MAX], visit[MAX][MAX], vvisit[MAX][MAX], num, max_area, extra_area, area;
std::map<int, int> ma;
std::queue<pos> q;

void print(int map[][MAX]) {
	F(x, m) {
		F(y, n) {
			std::cout << map[x][y] << ' ';
		}std::cout << '\n';
	}std::cout << '\n';
}

int main() {
	memset(visit, 0, sizeof(visit));
	memset(map, 0, sizeof(map));

	std::cin >> n >> m;
	F(x, m) F(y, n) std::cin >> map[x][y];

	// 벽 연결
	F(x, m) F(y, n) {
		if (visit[x][y]) continue;
		visit[x][y] = ++num;

		
		q.push({ x, y });
		area = 1;

		while (!q.empty()) {
			int tx = q.front().x;
			int ty = q.front().y;
			q.pop();

			int dir[4] = { 0, };
			if (!(map[tx][ty] & 1)) dir[0] = true;
			if (!(map[tx][ty] & 2)) dir[1] = true;
			if (!(map[tx][ty] & 4)) dir[2] = true;
			if (!(map[tx][ty] & 8)) dir[3] = true;


			F(a, 4) {
				if (!dir[a]) continue;

				int nx = tx + dx[a];
				int ny = ty + dy[a];

				if (nx < 0 || ny < 0 || nx >= m || ny >= n || visit[nx][ny]) continue;

				visit[nx][ny] = num;
				q.push({ nx, ny });
				area++;
			}
		}
		ma[num] = area;
		max_area = MA(max_area, area);
	}


	//print(visit);


	// 각각의 벽에서 벽 다 뚫어보기
	for (int i = 1; i <= num; ++i) {
		F(x, m) F(y, n) {
			if (visit[x][y] != i || vvisit[x][y]) continue;

			memset(vvisit, 0, sizeof(vvisit));

			q.push({ x,y });
			vvisit[x][y] = true;

			while (!q.empty()) {
				int tx = q.front().x;
				int ty = q.front().y;
				q.pop();

				F(a, 4) {
					int nx = tx + dx[a];
					int ny = ty + dy[a];

					if (nx < 0 || ny < 0 || nx >= m || ny >= n || vvisit[nx][ny]) continue;

					vvisit[nx][ny] = i;

					if (visit[nx][ny] != visit[x][y]) {
						extra_area = MA(ma[visit[x][y]] + ma[visit[nx][ny]], extra_area);
						continue;
					}

					q.push({ nx, ny });
				}
			}
		}
	}

	std::cout << num << '\n' << max_area << '\n' << extra_area;
	return 0;
}