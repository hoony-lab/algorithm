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

int dx[] = { 0, -1,0, 1 }, dy[] = { 1,0,-1,0 };
int map[MAX][MAX], cmap[MAX][MAX];
int cnt[MAX][4];
int visit[MAX][MAX][MAX][4];
int n, m, ans = 1e9;

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= m || map[x][y] == 6);
}

void dfs(int depth) {
	if (depth == (int)cctv.size()) {
		int area = 0;
		F(x, n) F(y, m) if (cmap[x][y] != 0) area++;
		ans = std::max(ans, area);
		return;
	}

	
	F(i, (int)cctv.size()) {
		cctv[i].x, cctv[i].y;
		
		search();
		dfs(depth + 1);
		search();
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
