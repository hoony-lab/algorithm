// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq
// 20210424 1235 - 1304
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
#pragma warning (disable : 4996)
#define F(i, n) for(int i = 0 ; i < n ; ++i)
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int T, n, k, map[10][10], visit[10][10], ans, top;
void print() {
	F(x, n) { F(y, n) { cout << map[x][y] << ' '; } cout << '\n'; }
}
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}
void dfs(int x, int y, int curr, int count, bool build) {

	visit[x][y] = true;
	
	ans = max(ans, count);

	F(a, 4) {
		int nx = x + dx[a], ny = y + dy[a], next = map[nx][ny];
		if (!check(nx, ny) || visit[nx][ny]) continue;
		
		if (curr > next) {
			dfs(nx, ny, next, count + 1, build);
		}
		else if(!build && curr > next - k) {
			dfs(nx, ny, curr - 1, count + 1, true);
		}
	}
	visit[x][y] = false;
}
int main() {

	freopen("input.txt", "r", stdin);
	cin >> T;

	F(test_case, T) {
		ans = 0, top = 0;
		memset(map, 0, sizeof(map));

		cin >> n >> k;
		F(x, n) F(y, n) cin >> map[x][y], top = max(top, map[x][y]);

		F(x, n) F(y, n) if (map[x][y] == top) {
			//cout << "start : " << x << ", " << y << '\n';
			memset(visit, 0, sizeof(visit));

			dfs(x, y, map[x][y], 1, false);
		}

		cout << "#" << test_case + 1 << " " << ans << '\n';
	}
	return 0;
}