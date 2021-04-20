#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstring>
#define F(i,n) for(int i = 0 ; i < n ; ++i)
#define MAX 2^6 + 1
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
struct P { int x, y; };
using namespace std;

int n, q, l;
int map[MAX][MAX], tmap[MAX][MAX], visit[MAX][MAX], max_ice_cnt , ice_cnt_total;

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}
int main() {
	cin >> n >> q;
	F(x, n) F(y, n) cin >> map[x][y];

	// firestorm()
	F(i, q) {
		cin >> l;
		
		// rotate()
		memset(tmap, 0, sizeof(tmap));
		memcpy(tmap, map, sizeof(tmap));
		int len = 1 << l;
		for (int sx = 0; sx < 1 << n; sx += len) {
			for (int sy = 0; sy < 1 << n; sy += len) {
				
				for (int x = 0; x < len; ++x) {
					for (int y = 0; y < len; ++y) {
						int nx = sx + x, ny = sy + y;
						tmap[nx][ny] = map[y][len - x];
						//0 0	0 3
						//0 1	1 3
						//0 2	2 3
						//0 3	3 3
						//1 0	0 2
						//1 1	1 2
					}
				}

			}
		}
		memcpy(map, tmap, sizeof(map));


		// melt();
		memset(tmap, 0, sizeof(tmap));
		memcpy(tmap, map, sizeof(tmap));

		F(x, n) F(y, n) {
			int cnt = 0;
			F(a, 4) {
				int nx = x + dx[a], ny = y + dy[a];
				if (!check(nx, ny)) continue;
				
				if(map[nx][ny]) cnt++;
			}
			if (cnt < 3) tmap[x][y]--;
		}

		memcpy(map, tmap, sizeof(map));
	}
	

	// bfs
	
	F(x, n) F(y, n) if(map[x][y] && !visit[x][y]) {
		int ice_cnt = 0;
		queue<P> q;
		q.push({ x, y });	visit[x][y] = true;
		ice_cnt++;	ice_cnt_total++;

		while (!q.empty()) {
			int tx = q.front().x, ty = q.front().y;
			q.pop();

			F(a, 4) {
				int nx = tx + dx[a], ny = ty + dy[a];
				if (!check(nx, ny)) continue;

				q.push({ nx, ny });	visit[nx][ny] = true;
				ice_cnt++;	ice_cnt_total++;
			}
		}

		max_ice_cnt = max(max_ice_cnt, ice_cnt);
	}
	
	cout << ice_cnt_total << '\n' << max_ice_cnt;
	return 0;
}