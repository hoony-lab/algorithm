// 20200602 1743
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(i ,n) for(int i = 0 ; i < n ; ++i)
#define MAX 101
struct p { int x, y, cnt; };
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };

//l명 이상, r명 이하
int n, l, r, map[MAX][MAX], group_map[MAX][MAX], group[MAX];
int visit[MAX][MAX];

void print(int map[][MAX]) {
	F(x, n) {
		F(y, n) {
			cout << map[x][y];
		}cout << '\n';
	}cout << "\n\n";
}

bool gap_check(int gap) {
	if (l <= gap && gap <= r) return true;
	return false;
}

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}

void bfs() {
	// F(i, MAX) fill(visit[i][0], visit[i][MAX], 0);
	int group_num = 0, group_cnt = 1;
	queue<p> q;
	memset(visit, 0, sizeof(visit));


	// group with possible gap
	F(x, n) F(y, n) {
		if (visit[x][y]) continue;

		visit[x][y] = ++group_num;
		q.push({ x,y });
		group_cnt = 1;
		group[group_num] = map[x][y];

		while (!q.empty()) {
			int tx = q.front().x, ty = q.front().y, tc = q.front().cnt;
			q.pop();

			F(a, 4) {
				int nx = tx + dx[a], ny = ty + dy[a];
				if (!check(nx, ny) || visit[nx][ny]) continue;


				// l <= gap <= r
				int gap = abs(map[nx][ny] - map[tx][ty]);
				if (!gap_check(gap)) continue;

				visit[nx][ny] = visit[tx][ty];
				q.push({ nx,ny });
				group_cnt++;
				group[group_num] += map[nx][ny];
			}
		}
	}

	F(x, n) F(y, n) {

	}
}

int main() {
	cin >> n >> l >> r;
	F(x, n) F(y, n) cin >> map[x][y];

	bfs();

	return 0;
}