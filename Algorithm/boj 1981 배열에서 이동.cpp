#include <iostream>
#include <set>
#include <queue>
using namespace std;
#define MAX 101
#define F(i,n) for(int i = 0 ; i < n ; ++i)
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int n, map[MAX][MAX], visit[MAX][MAX], min_max_min_dist_gap = 1e9;

struct P { int x, y; set<int> s; };
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> n; F(x, n) F(y, n) cin >> map[x][y];

	// bfs
	queue<P> q;
	q.push({ 0,0 });
	visit[0][0] = 1;

	while (!q.empty()) {
		int tx = q.front().x, ty = q.front().y;
		set<int> ts = q.front().s;
		q.pop();

		F(a, 4) {
			int nx = tx + dx[a], ny = ty + dy[a];
			set<int> ns = ts;
			ns.insert(map[nx][ny]);

			if (!check(nx, ny)
				|| (visit[nx][ny] != 0 && visit[tx][ty] > visit[nx][ny])) continue;
			
			//cout << nx << ", " << ny << '\n';

			if (nx == n - 1 && ny == n - 1) {
				//cout << *--ns.end() - *ns.begin() << '\n';
				min_max_min_dist_gap = min(min_max_min_dist_gap, *--ns.end() - *ns.begin());
				continue;
			}

			q.push({ nx, ny, ns });
			visit[nx][ny] = visit[tx][ty] + 1;
		}
	}

	cout << min_max_min_dist_gap;
	return 0;
}