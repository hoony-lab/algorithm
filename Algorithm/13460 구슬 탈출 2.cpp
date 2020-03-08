#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

bool fail, done;
int n, m, rx, ry, bx, by, endx, endy, cnt;
char map[11][11];
int visited[11][11];

int main() {
	done = false;
	fail = false;
	cnt = 0;
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));

	cin >> n >> m;

	
	char ch;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			cin >> map[x][y];
			if (map[x][y] == 'R') {
				rx = x;
				ry = y;
			}
			if (map[x][y] == 'B') {
				bx = x;
				by = y;
			}
			if (map[x][y] == 'O') {
				endx = x;
				endy = y;
			}
		}
	}

	queue<pair<int, int>> rq, bq;
	rq.push(make_pair(rx, ry));
	bq.push(make_pair(bx, by));

	visited[rx][ry] = 1;
	visited[bx][by] = 1;

	while (!rq.empty()) {
		int rtx = rq.front().first;
		int rty = rq.front().second;
		rq.pop();
		int btx = bq.front().first;
		int bty = bq.front().second;
		bq.pop();

		int slide = 1;
		bool wall;
		for (int a = 0; a < 4; a++) {
			int rnx;
			int rny;
			int bnx;
			int bny;

			//red silde
			wall = false;
			while (wall) {
				int rnx = rtx + dx[a] * slide;
				int rny = rty + dy[a] * slide;

				if (map[rnx][rny] == '#' || map[rnx][rny] == 'B') continue;



			}

			//blue silde
			wall = false;
			while (wall) {
				int bnx = btx + dx[a] * slide;
				int bny = bty + dy[a] * slide;

				if (map[bnx][bny] == '#' || map[bnx][bny] == 'R') continue;

			}

			//done answer
			if (map[rnx][rny] == 'O') {
				done = true;
				break;
			}
			//fail answer
			
			if (cnt > 10) {
				fail = true;
				cnt = -1;
			}

			slide++;
		}

		if (done) break;
	}




	cout << cnt;

	return 0;
}
