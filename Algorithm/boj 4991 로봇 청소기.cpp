/// 20200517 0947 1028
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <cstring>
#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define MAX 21
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define FA(i, n) for(auto i : n)
struct P { int x, y; }sp, ep;
bool operator<(const P p1, const P p2) { return p1.x < p2.x; }

using vP = std::vector < P >;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1,0,-1,0 };

int dist[MAX][MAX];
char map[MAX][MAX];
bool visit_trash[MAX];
int m, n, ans;
vP v;
std::set<P> st;

void print(char visit[][MAX]) {
	F(x, n) { F(y, m) { if (map[x][y] == 'x') std::cout << "X "; else std::cout << visit[x][y] << " "; }std::cout << '\n'; }std::cout << "\n\n";
}
void print(int visit[][MAX]) {
	F(x, n) { F(y, m) { if (map[x][y] == 'x') std::cout << "X "; else std::cout << visit[x][y] << " "; }std::cout << '\n'; }std::cout << "\n\n";
}

int bfs(int s, int e) {
	int sx = v[s].x, sy = v[s].y;
	int ex = v[e].x, ey = v[e].y;

	int visit[MAX][MAX]{};	visit[sx][sy] = 1;
	std::queue<P> q;		q.push({ sx, sy });

	while (!q.empty()) {
		int tx = q.front().x, ty = q.front().y;		q.pop();
		//print(visit);
		F(a, 4) {
			int nx = tx + dx[a], ny = ty + dy[a];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny] || map[nx][ny] == 'x') continue;

			visit[nx][ny] = visit[tx][ty] + 1;
			q.push({ nx, ny });

			if (nx == ex && ny == ey) {
				//std::cout << sx << ", " << sy << " ::: " << ex << ", " << ey <<  " ::: " << visit[nx][ny] - 1 << '\n';
				return visit[nx][ny] - 1;
			}
		}
	}
	return 1e5;
}

void dfs(int sum, int depth, int start, bool visit_trash[]) {

	if (depth == v.size() - 1) {
		//std::cout << ans << ", " << sum << '\n';
		if (ans > sum) ans = sum;
	}

	F(i, v.size()) {
		if (visit_trash[i] || dist[start][i] == 1e5) continue;

		visit_trash[i] = true;
		dfs(sum + dist[start][i], depth + 1, i, visit_trash);
		visit_trash[i] = false;
	}
}


int main() {
	FIO;

	while (true) {
		memset(visit_trash, 0, sizeof(visit_trash));
		memset(map, 0, sizeof(map));
		v.clear();
		ans = 1e5;

		std::cin >> m >> n; if (!m) break;
		F(x, n) F(y, m) {
			std::cin >> map[x][y];
			if (map[x][y] == '*') v.push_back({ x, y });
			else if (map[x][y] == 'o') sp.x = x, sp.y = y;
		}
		v.push_back(sp);

		F(i, v.size()) {
			F(j, v.size()) {
				if (j <= i) continue;
				int d = bfs(i, j);
				dist[i][j] = dist[j][i] = d;
				//std::cout << i << ", " << j << " :: " << d << '\n';
			}
		}

		visit_trash[v.size() - 1] = true;
		dfs(0, 0, v.size() - 1, visit_trash);

		if (ans == 1e5) std::cout << -1 << '\n';
		else			std::cout << ans << '\n';
	}
	return 0;
}