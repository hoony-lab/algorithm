// https://www.acmicpc.net/problem/15683
// 20200503 1131
#include <iostream>
#include <vector>
#include <queue>
#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 10

struct P { int x, y; };
using vP = std::vector<P>;
using vi = std::vector<int>;
vP cctv, wall;

// R 
int dx[] = { 0, -1,0, 1 }, dy[] = { 1,0,-1,0 };
int way[][6] = { {},
	{0, 1, 2, 3},
	{},

};
int map[MAX][MAX], cmap[MAX][MAX];
int cnt[MAX][4];
int visit[MAX][MAX][MAX][4];
int n, m, ans = 1e9;

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= m || map[x][y] == 6);
}
void search(int x, int y, int w, bool chk) {
	F(x, n) F(y, m) {
		chk ? map[x][y] = 1 : map[x][y] = 0;

	}
}

void dfs(int depth) {
	if (depth == (int)cctv.size()) {
		int area = 0;
		F(x, n) F(y, m) if (cmap[x][y] != 0) area++;
		ans = std::max(ans, area);
		return;
	}

	
	int x = cctv[i].x, y = cctv[i].y;
	F(i, (int)cctv.size()) {
		
		search(x, y, , true);
		dfs(depth + 1);
		search(x, y, , false);
	}
}
int main() {
	FIO;
	std::cin >> n >> m;
	F(x, n) F(y, m) {
		std::cin >> map[x][y];
		if (0 < map[x][y] && map[x][y] < 6) cctv.push_back({ x,y });
		//else if (map[x][y] == 6) wall.push_back({ x,y });
	}

	dfs(0);


	//F(i, (int)cctv.size()) {
	//	int tx = cctv[i].x, ty = cctv[i].y;
	//	int num = map[tx][ty];


	//	std::cout << "check : " << tx << ", " << ty << " :: " << num << '\n';

	//	// count length of each ways from cctv
	//	F(a, 4) {
	//		int nx = tx + dx[a], ny = ty + dy[a];

	//		while (check(nx, ny) && map[nx][ny] != 6) {
	//			if (0 < map[nx][ny] && map[nx][ny] < 6) continue;
	//			std::cout << "loop : " << nx << ", " << ny << '\n';
	//			nx += dx[a], ny += dy[a];

	//			cnt[i][a]++;
	//			visit[i][nx][ny][a] = 1;
	//		}
	//	}

	//}


		//// get max_cnt from length of each ways
		//int max_cnt = 0;
		//vi max_idx;

		//switch (num) {
		//case 1:
		//	F(a, 4) if (cnt[i][a] > max_cnt)
		//		max_cnt = cnt[i][a], max_idx.push_back(a);
		//	break;
		//case 2:
		//	if (cnt[i][0] + cnt[i][2] > cnt[i][1] + cnt[i][3])
		//		max_cnt = cnt[i][0] + cnt[i][2], max_idx.push_back(0), max_idx.push_back(2);
		//	else max_cnt = cnt[i][1] + cnt[i][3], max_idx.push_back(1), max_idx.push_back(3);
		//	break;
		//case 3:
		//	F(a, 4) max_cnt = std::max(cnt[i][a] + cnt[i][(a + 1) % 4], max_cnt);
		//	break;
		//case 4:
		//	F(a, 4) max_cnt = std::max(cnt[i][a] + cnt[i][(a + 1) % 4] + cnt[i][(a + 2) % 4], max_cnt);
		//	break;
		//case 5:
		//	F(a, 4) max_cnt += cnt[i][a];
		//	break;
		//}
		//
		//ans += max_cnt;

	
	
	std::cout << n * m << ", " << ans << ", " << cctv.size() << ", " << wall.size() << '\n';
	std::cout << n * m - (ans + (int)cctv.size() + (int)wall.size()) << '\n';
	return 0;
}


/*
#include <cstdio>
#include <vector>
using namespace std;

struct cctv {
	int x, y, id;
};

int n, m, ans=1e9;
int a[10][10], b[10][10];
vector<cctv> v;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const int U = 1, R = 1<<1, D = 1<<2, L = 1<<3;
vector<int> direct[6] = {{},
	{U, R, D, L}, // CCTV 1 : One direction
	{U|D, R|L},   // CCTV 2 : Two direction (180 degree)
	{U|R, R|D, D|L, L|U},         // CCTV 3 : Two direction (90 degree)
	{L|U|R, U|R|D, R|D|L, D|L|U}, // CCTV 4 : Three direction
	{U|R|D|L}};   // CCTV 5 : Four direction

void observe(int x, int y, int i, int d) {
	// CCTV observation. d==1(On), d==-1(off)
	for (int k=0; k<4; k++) {
		if (i & (1<<k)) {
			int nx = x, ny = y;
			while (a[nx][ny] != 6) {
				b[nx][ny] += d;
				nx += dx[k], ny += dy[k];
			}
		}
	}
}

void solve(int index) {
	if (index == (int)v.size()) {
		// Count blind areas.
		int area = 0;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				if (b[i][j] == 0) area += 1;
			}
		}
		if (ans > area) ans = area;
		return;
	}
	int x = v[index].x, y = v[index].y, id = v[index].id;
	for (auto i : direct[id]) {
		observe(x, y, i, 1);  // Turn on cctv.
		solve(index+1);
		observe(x, y, i, -1); // Turn off cctv.
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i=0; i<n+2; i++) {
		for (int j=0; j<m+2; j++) {
			if (i == 0 || i == n+1 || j == 0 || j == m+1) a[i][j] = 6;
			else {
				scanf("%d", &a[i][j]);
				if (a[i][j] == 6) b[i][j] = 1;
				else if (a[i][j] != 0) v.push_back({i, j, a[i][j]});
			}
		}
	}
	solve(0);
	printf("%d\n", ans);
	return 0;
}


ÃâÃ³: https://rebas.kr/732 [PROJECT REBAS]
*/