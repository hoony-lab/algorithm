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

char map[MAX][MAX];
bool visit_trash[MAX];
int m, n, ans;
vP v;
std::set<P> st;


void print(char visit[][MAX]) {
	F(x, n) { F(y, m) { if (map[x][y] == 'x') std::cout << "X "; else std::cout << visit[x][y] << " "; }std::cout << '\n'; }std::cout << "\n\n";
}
void print(int visit[][MAX]) {
	F(x, n) { F(y, m) { if(map[x][y] == 'x') std::cout << "X "; else std::cout << visit[x][y] << " "; }std::cout << '\n'; }std::cout << "\n\n";
}

int bfs(P sp, int trash_num) {
	int sx = sp.x, sy = sp.y;
	int ex = v[trash_num].x, ey = v[trash_num].y;

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

void dfs(P sp, bool visit_trash[], char map[][MAX], int time, int depth) {

	if (depth == v.size()) {
		//std::cout << ans << ", " << time << '\n';
		if (ans > time) ans = time;
	}

	F(trash_num, v.size()) {
		if (visit_trash[trash_num]) continue;

		char cmap[MAX][MAX];	memcpy(cmap, map, sizeof(map));		
		int find_time = bfs(sp, trash_num);

		visit_trash[trash_num] = true;
		dfs(v[trash_num], visit_trash, cmap, time + find_time, depth + 1);
		visit_trash[trash_num] = false;
	}
}


int main() {
	FIO;

	while (true) {
		memset(visit_trash, 0, sizeof(visit_trash));
		memset(map, 0, sizeof(map));
		v.clear(); 
		ans = 1e9;

		std::cin >> m >> n; if (!m) break;
		F(x, n) F(y, m) {
			std::cin >> map[x][y];
			if (map[x][y] == '*') v.push_back({ x, y });
			else if (map[x][y] == 'o') sp.x = x, sp.y = y;
		}

		char cmap[MAX][MAX];	memcpy(cmap, map, sizeof(map));
		dfs(sp, visit_trash, cmap, 0, 0);

		if (ans == 1e5) std::cout << -1 << '\n';
		else			std::cout << ans << '\n';

		//bool fail = false;
		//F(x, n) F(y, m) if (map[x][y] == '*') fail = true;
		//	
		//if(fail)	std::cout << -1 << '\n';
		//else		std::cout << time << '\n';
	}
	return 0;
}