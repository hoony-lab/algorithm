#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
#include <iostream>
#define MAX 101
using namespace std;
//struct P { int x, y, cnt, visit[MAX][MAX]{}; };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int r, c, t, sx, sy, ans;
char map[MAX][MAX];

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= r || y >= c);
}

void dfs(int tx, int ty, int cnt, int visit[MAX][MAX]) {

	if (visit[tx][ty] > t) {
		ans = max(ans, cnt);
		return;
	}
	
	for (int a = 0; a < 4; ++a) {
		int nx = tx + dx[a], ny = ty + dy[a], ncnt = cnt;

		if (!check(nx, ny) || map[nx][ny] == '#') continue;

		//cout << "\tvisit : " << nx << ", " << ny << " : " << visit[tx][ty] << '\n';

		if (map[nx][ny] == 'S' && !visit[nx][ny]) ncnt++;
		int nvisit = visit[nx][ny];
		visit[nx][ny] = visit[tx][ty] + 1;
		dfs(nx, ny, ncnt, visit);
		visit[nx][ny] = nvisit;
		if (map[nx][ny] == 'S' && !visit[nx][ny]) ncnt--;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> t;
	for (int x = 0; x < r; ++x) {
		for (int y = 0; y < c; ++y) {
			cin >> map[x][y];
			if (map[x][y] == 'G') {
				sx = x, sy = y;
			}
		}
	}

	int visit[MAX][MAX]{};
	visit[sx][sy] = 1;
	dfs(sx, sy, 0, visit);

	/*
	queue<P> q;
	q.push({ sx,sy,0 });
	visit[sx][sy] = 1;

	while (!q.empty()) {
		int tx = q.front().x, ty = q.front().y, cnt = q.front().cnt, tvisit[MAX][MAX]{};
		memcpy(tvisit, q.front().visit, sizeof(tvisit));
		q.pop();
		//cout << "START : " << tx << ", " << ty << '\n';

		for (int a = 0; a < 4; ++a) {
			int nx = tx + dx[a], ny = ty + dy[a], ncnt = cnt;
			
			if (!check(nx, ny) || map[nx][ny] == '#') continue;

			if (map[nx][ny] == 'S' && !tvisit[nx][ny]) ncnt++;

			if (tvisit[tx][ty] > t) {
				ans = max(ans, ncnt);
				//cout << "\t\tEND : " << nx << ", " << ny << " : " << ncnt << ", " << ans << '\n';
				continue;
			}
			
			tvisit[nx][ny] = tvisit[tx][ty] + 1;
			P p;
			p.x = nx, p.y = ny, p.cnt = ncnt;
			memcpy(p.visit, tvisit, sizeof(p.visit));
			q.push(p);
			//cout << "\tPUSH : " << nx << ", " << ny << '\n';
		}
	}
	*/

	cout << ans;
	return 0;
}
/*
11 11 5
.......SG..
........#S.
........#..
...........
..........S
.##########
.##########
...........
...........
##########.
...........
*/