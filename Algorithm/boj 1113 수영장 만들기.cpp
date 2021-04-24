// 20210424 1437
#include <iostream>
#include <queue>
#define F(i, n) for(int i = 0 ; i < n ; ++ i)
#define FS(s, i, n) for(int i = s ; i < n ; ++ i)
#define MAX 50
using namespace std;
struct P { int x, y, h; };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int n, m, map[MAX][MAX], visit[MAX][MAX], min_water = 1e9, max_water, block[10];
void print(int m[][MAX]) {
	F(x, n) { F(y, m) { cout << m[x][y] << " "; } cout << '\n'; } cout << '\n';
}
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= m);
}
int main() {
	cin >> n >> m; 
	F(x, n) F(y, n) {
		cin >> map[x][y];
		min_water = min(min_water, map[x][y]);
		max_water = max(max_water, map[x][y]);
		block[map[x][y]]++;
	}

	F(x, n) F(y, m) if(!visit[x][y]) {
		queue<P> q;
		q.push({ x, y }); visit[x][y] = 1;
	}
	
	int is_dead[MAX * MAX + 1]{};
	int num = 0;
	for (int height = max_water; height >= min_water; --height) {
		F(x, n) F(y, m) if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
			queue<P> q;
			q.push({ x, y }), visit[x][y] = num;

			while (!q.empty()) {
				int tx = q.front().x, ty = q.front().y;
				q.pop();

				F(a, 4) {
					int nx = tx + dx[a], ny = ty + dy[a];

					if (!check(nx, ny)) {
						is_dead[num] = true;
						continue;
					}

					// 현재 물의 높이보다 높거나 같을떄 물이 못지나감
					if (map[nx][ny] >= height) continue;

					q.push({ nx, ny });
					visit[nx][ny] = num;
				}
			}

			num++;
		}
	}
	print(visit);
	
	//FS(1, x, n - 1) FS(1, y, m - 1) {
	//	queue<P>
	//	F(a, 4) {
	//		if (!check(nx, ny)) {
	//			dead = true;
	//		}
	//	}

	//}

	return 0;
}