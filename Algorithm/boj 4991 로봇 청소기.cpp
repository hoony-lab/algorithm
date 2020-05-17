/// 20200517 0947
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
struct P { int x, y; };
bool operator<(const P p1, const P p2) { return p1.x < p2.x; }

using vP = std::vector < P >;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1,0,-1,0 };

char map[MAX][MAX];
int m, n, sx, sy, ans;
//vP v;
std::set<P> st;
void print(int visit[][MAX]) {
	F(x, n) { F(y, m) { std::cout << visit[x][y]; }std::cout << '\n'; }std::cout << "\n\n";
}

void bfs(int sx, int sy) {
	int visit[MAX][MAX]{};	visit[sx][sy] = 1;
	std::queue<P> q;		q.push({ sx, sy });

	while (!q.empty()) {
		int tx = q.front().x, ty = q.front().y;		q.pop();

		F(a, 4) {
			int nx = tx + dx[a], ny = ty + dy[a];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny] || map[nx][ny] == 'x') continue;

			visit[nx][ny] = visit[tx][ty] + 1;
			q.push({ nx, ny });

			if (map[nx][ny] == '*') {
				//std::cout << ans << " Find : " << nx << ", " << ny << '\n';
				//print(visit);

				ans += visit[nx][ny] - 1;

				FA(i, st) if (i.x == nx && i.y == ny) {
					st.erase(i); break;
				}
				map[nx][ny] = '.';


				memset(visit, 0, sizeof(visit));
				while (!q.empty()) q.pop();
				
				bfs(nx, ny);
				return;
			}


		}
	}


}
int main() {
	FIO;

	while (true) {
		memset(map, 0, sizeof(map));
		ans = 0;
		st.clear();

		std::cin >> m >> n; if (!m) break;
		F(x, n) F(y, m) {
			std::cin >> map[x][y];
			if (map[x][y] == '*') st.insert({ x, y });
			else if (map[x][y] == 'o') sx = x, sy = y;
		}

		bfs(sx, sy);

		if (st.size())	std::cout << -1 << '\n';
		else			std::cout << ans << '\n';
	}
	return 0;
}