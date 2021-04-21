#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstring>
#define F(i,n) for(int i = 0 ; i < n ; ++i)
#define MAX (1 << 6) + 1
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
struct P { int x, y; };
using namespace std;

int n, q, l, nn;
int map[MAX][MAX], tmap[MAX][MAX], visit[MAX][MAX], max_ice_cnt , ice_cnt_total;

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= nn || y >= nn);
}
void print(int m[][MAX]) {
	cout << '\n';
	F(x, nn) {
		F(y, nn) {
			if(m[x][y] < 1) cout << "- ";
			else cout << m[x][y] << ' ';
		}cout << '\n';
	}
}
int main() {
	cin >> n >> q;
	nn = 1 << n;
	F(x, nn) F(y, nn) cin >> map[x][y];
	
	// firestorm()
	F(i, q) {
		cin >> l;
		
		// rotate()
		memset(tmap, 0, sizeof(tmap));
		memcpy(tmap, map, sizeof(tmap));
		int len = 1 << l;
		for (int sx = 0; sx < nn; sx += len) {
			for (int sy = 0; sy < nn; sy += len) {
				
				for (int x = 0; x < len; ++x) {
					for (int y = 0; y < len; ++y) {
						tmap[sx + x][sy + y] = map[sx + (len - 1 - y)][sy + x];
						//cout << "\trotate : " << sx + (len - 1 - y) << ", " << sy + x << " (" << map[sx + (len - 1 - y)][sy + x] << ") : " << sx + x << ", " << sy + y << '\n';
						/*
						0 0			4 4
						3 0	> 0 0		7 4		4 4
						2 0	> 0 1		6 4		4 5
						1 0	> 0 2
						0 0	> 0 3
						0 1 > 1 0

						3 1 > 1 0
						2 1 > 1 1
						1 1 > 1 2
						0 1 > 1 3

						3 5 > 1 4
						2 5 > 1 5
						1 5 > 1 6
						0 5 > 1 7



						 1 0 < 3 1 
						 1 1 < 2 1 
						 1 2 < 1 1 
						 1 3 < 0 1 
							 < 
						 1 4 < 3 5 
						 1 5 < 2 5 
						 1 6 < 1 5 
						 1 7 < 0 5 

						rotate : 1, 1 : 0, 0
						rotate : 0, 1 : 0, 1
						rotate : 1, 0 : 1, 0
						rotate : 0, 0 : 1, 1

						1 2 > 0 2
						0 2 > 0 3
						1 3 > 1 2
						0 3 > 1 3
						*/
					}
				}

			}
		}
		memcpy(map, tmap, sizeof(map));

		// melt();
		memset(tmap, 0, sizeof(tmap));
		memcpy(tmap, map, sizeof(tmap));
		F(x, nn) F(y, nn) {
			int cnt = 0;

			F(a, 4) {
				int nx = x + dx[a], ny = y + dy[a];
				if (!check(nx, ny)) continue;
				
				if (map[nx][ny] > 0) cnt++;
			}
			if (cnt < 3) tmap[x][y]--;
		}
		memcpy(map, tmap, sizeof(map));
		//cout << "MELT\n";  print(map);
	}

	// bfs
	F(x, nn) F(y, nn) if(map[x][y] > 0 && !visit[x][y]) {
		//cout << "START : " << x << ", " << y << " : " << map[x][y] << '\n';
		int ice_cnt = 0;
		queue<P> q;
		q.push({ x, y });	visit[x][y] = true;
		ice_cnt++;	ice_cnt_total += map[x][y];

		while (!q.empty()) {
			int tx = q.front().x, ty = q.front().y;
			q.pop();

			F(a, 4) {
				int nx = tx + dx[a], ny = ty + dy[a];
				if (!check(nx, ny) || visit[nx][ny] || map[nx][ny] < 1) continue;

				q.push({ nx, ny });	visit[nx][ny] = true;
				ice_cnt++;	ice_cnt_total += map[nx][ny];
			}
		}
		//print(visit);
		max_ice_cnt = max(max_ice_cnt, ice_cnt);
	}
	
	cout << ice_cnt_total << '\n' << max_ice_cnt;
	return 0;
}