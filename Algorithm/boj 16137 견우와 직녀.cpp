#include <iostream>
#include <queue>
#include <vector>
#define F(i,n) for(int i = 0 ; i < n ; ++i)
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int n, m, ans = 1e9;
int map[11][11], visited[11][11][2];
using namespace std;

struct p { int x, y, b; };

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}

void check_bridge() {
	F(x, n) {
		F(y, n) {
			if (map[x][y] == 1) continue;

			int way[4]{};
			F(a, 4) {
				int nx = x + dx[a];
				int ny = y + dy[a];

				if (!check(nx, ny)) continue;

				if (map[x][y] <= 0 && map[nx][ny] <= 0) way[a] = 1;
			}
			F(a, 4) {
				if (way[a] && way[(a + 1) % 4]) map[x][y] = -1;
			}
		}
	}
}

void print() {
	cout << "\n\n";

	F(x, n) {
		F(y, n) {
			cout << map[x][y] << " ";
		}cout << '\n';
	}cout << "\n\n";

	F(x, n) {
		F(y, n) {
			cout << visited[x][y][0] << " ";
		}cout << '\n';
	}cout << "\n\n";

	F(x, n) {
		F(y, n) {
			cout << visited[x][y][1] << " ";
		}cout << '\n';
	}cout << "\n\n";
}

int main() {
	cin >> n >> m;
	F(x, n) F(y, n) cin >> map[x][y];

	check_bridge();

	queue<p> q;
	q.push({ 0, 0 });
	visited[0][0][0] = 0;

	while (!q.empty()) {
		int tx = q.front().x;
		int ty = q.front().y;
		int tb = q.front().b;
		q.pop();

		F(a, 4) {
			int nx = tx + dx[a];
			int ny = ty + dy[a];
			int nb = tb;
			if (!check(nx, ny) || map[nx][ny] == -1) continue;

			if (nx == n - 1 && ny == n - 1) {
				visited[tx][ty][0] == 0 ?
					ans = min(ans, visited[tx][ty][1] + 1) :
					ans = min(ans, visited[tx][ty][0] + 1);
			}

			if (map[nx][ny] == 1 && !visited[nx][ny][tb]) {
				q.push({ nx, ny, tb });
				visited[nx][ny][tb] = visited[tx][ty][tb] + 1;
			}
			else if (map[nx][ny] == 0 && tb == 0
				&& (visited[tx][ty][tb] + 1) % m == 0
				&& !visited[nx][ny][tb + 1]) {

				nb = tb + 1;
				q.push({ nx, ny, nb });
				visited[nx][ny][nb] = visited[tx][ty][tb] + 1;
			}
			else if (map[nx][ny] == visited[tx][ty][tb] + 1
				&& !visited[nx][ny][tb]
				) {	// 6

				q.push({ nx, ny, tb });
				visited[nx][ny][tb] = visited[tx][ty][tb] + 1;
			}
		}
	}

	cout << ans;
	//print();
	return 0;
}
/*
5 5
1 1 0 1 1
0 6 0 0 0
1 0 0 1 1
0 1 0 1 1
1 1 0 1 1

5 5
1 1 1 1 0
0 6 0 0 0
1 0 0 1 1
0 1 0 1 1
1 1 0 1 1

5 5
1 1 1 1 1
0 6 0 0 0
1 0 0 1 1
0 1 0 1 1
1 1 0 1 1

5 4
1 1 1 1 1
0 6 0 0 0
1 0 0 1 1
0 1 0 1 1
1 1 0 1 1

5 5
1 1 0 1 1
1 1 0 0 0
1 0 0 1 1
3 1 0 1 1
1 1 0 1 1


8 2
1 1 1 1 0 1 1 1
1 1 0 1 0 1 0 1
0 0 0 1 1 1 0 1
0 0 0 0 0 0 0 1
0 0 0 0 0 1 0 1
0 0 0 0 0 1 1 1
0 0 0 0 0 0 0 10
0 0 0 0 0 0 1 1

5 10
1 1 2 3 1
1 1 0 0 1
13 0 0 0 1
1 1 1 1 1
1 1 1 1 1

*/

/*
https://newbrother.github.io/BOJ-16137/
#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;
int n, m;
int a[10][10];
//dist: x,y,waiting
int dist[10][10][20];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int bfs() {
	memset(dist,-1,sizeof(dist));
	queue<tuple<int,int,int>> q;
	q.push(make_tuple(0,0,0));
	dist[0][0][0] = 0;
	while (!q.empty()) {
		int x,y,t;
		tie(x,y,t) = q.front();
		q.pop();
		if (a[x][y] >= 2 && t % a[x][y] != 0) {
			int nt = (t+1)%a[x][y];
			if (dist[x][y][nt] == -1) {
				dist[x][y][nt] = dist[x][y][t] + 1;
				q.push(make_tuple(x,y,nt));
			}
		} else {
			for (int k=0; k<4; k++) {
				int nx = x+dx[k];
				int ny = y+dy[k];
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (a[x][y] >= 2 && a[nx][ny] >= 2) continue;
					if (a[nx][ny] >= 1) {
						int nt = (dist[x][y][t]+1)%a[nx][ny];
						if (dist[nx][ny][nt] == -1) {
							dist[nx][ny][nt] = dist[x][y][t] + 1;
							q.push(make_tuple(nx,ny,nt));
						}
					}
				}
			}
		}
	}
	return dist[n-1][n-1][0];
}
bool can(int i, int j) {
	bool garo = false;
	if (j-1 >= 0 && a[i][j-1] == 0) garo = true;
	if (j+1 < n && a[i][j+1] == 0) garo = true;
	bool sero = false;
	if (i-1 >= 0 && a[i-1][j] == 0) sero = true;
	if (i+1 < n && a[i+1][j] == 0) sero = true;
	return !(garo && sero);
}
int main() {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}
	int ans = -1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (a[i][j] == 0 && can(i, j)) {
				a[i][j] = m;
				int now = bfs();
				if (now != -1) {
					if (ans == -1 || ans > now) {
						ans = now;
					}
				}
				a[i][j] = 0;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

*/