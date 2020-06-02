// https://www.acmicpc.net/problem/16234
// 20200602 1743
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
//#include <bits/stdc++.h>
//using namespace std;
#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 101
struct p { int x, y; };
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };

//l명 이상, r명 이하
int n, l, r, ans, area[MAX][MAX];
///		배열 크기 RunTime Error
int visit[MAX][MAX], group_sum[MAX * MAX], group_cnt[MAX * MAX];

//void print(int area[][MAX]) {
//	F(x, n) {
//		F(y, n) {
//			cout << area[x][y];
//		}cout << '\n';
//	}cout << "\n\n";
//}

bool gap_check(int gap) {
	if (l <= gap && gap <= r) return true;
	return false;
}

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}

void bfs() {
	while (1) {
		// F(i, MAX) fill(visit[i][0], visit[i][MAX], 0);
		std::queue<p> q;
		int group_num = 0;
		memset(visit, 0, sizeof(visit));
		memset(group_sum, 0, sizeof(group_sum));
		memset(group_cnt, 0, sizeof(group_cnt));

		// group with possible gap
		F(x, n) F(y, n) {
			if (visit[x][y]) continue;
			visit[x][y] = ++group_num;
			q.push({ x,y });
			group_cnt[group_num]++;
			group_sum[group_num] = area[x][y];

			while (!q.empty()) {
				int tx = q.front().x, ty = q.front().y;
				q.pop();

				F(a, 4) {
					int nx = tx + dx[a], ny = ty + dy[a];
					if (!check(nx, ny) || visit[nx][ny]) continue;

					// l <= gap <= r
					int gap = std::abs(area[nx][ny] - area[tx][ty]);
					if (!gap_check(gap)) continue;

					visit[nx][ny] = visit[tx][ty];
					q.push({ nx,ny });
					group_cnt[group_num]++;
					group_sum[group_num] += area[nx][ny];
				}
			}

		}

		//cout << "Turn : " << ans << '\n';
		//print(map);
		//print(visit);

		if (group_num == n * n) break;

		ans++;

		F(x, n) F(y, n)
			area[x][y] = group_sum[visit[x][y]] / group_cnt[visit[x][y]];
	}
}

int main() {
	FIO;
	std::cin >> n >> l >> r;
	F(x, n) F(y, n) std::cin >> area[x][y];

	bfs();

	std::cout << ans;
	return 0;
}