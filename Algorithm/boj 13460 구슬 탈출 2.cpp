#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <memory.h>
using namespace std;

const int dx[] = { 0,1,0,-1 };
const int dy[] = { 1,0,-1,0 };

bool fail, done;
int n, m, rx, ry, bx, by, ans, answer;
char map[11][11];
int visited[11][11][11][11];

bool red_slide(int &rnx, int &rny, int a) {

	while (1) {
		if (map[rnx][rny] == '#' || map[rnx][rny] == 'B') return true;

		//done answer
		if (map[rnx][rny] == 'O') {
			done = true;
			return true;
		}

		rnx += dx[a];
		rny += dy[a];
	}
}

bool blue_slide(int &bnx, int &bny, int a) {

	while (1) {
		if (map[bnx][bny] == '#' || map[bnx][bny] == 'A') return true;

		//파랑공이 빠지면 안됌
		if (map[bnx][bny] == 'O') {
			if (done) fail = true;
			return false;
		}

		bnx += dx[a];
		bny += dy[a];
	}
}

int main() {

	done = false;
	fail = false;
	ans = 0;
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));

	cin >> n >> m;

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			cin >> map[x][y];
			if (map[x][y] == 'R') rx = x, ry = y;
			if (map[x][y] == 'B') bx = x, by = y;
		}
	}ㅇ

	queue<tuple<int, int, int>> rq;
	queue<pair<int, int>> bq;

	rq.push(make_tuple(rx, ry, ans));
	bq.push(make_pair(bx, by));
	visited[rx][ry][bx][by] = 1;

	while (!rq.empty()) {
		int rtx = get<0>(rq.front()), rty = get<1>(rq.front()), ans = get<2>(rq.front());
		int btx = bq.front().first, bty = bq.front().second;
		rq.pop();
		bq.pop();

		//answer = ans + 1;
		

		//std::cout << rtx << ", " << rty << " :: " << btx << ", " << bty << '\n';

		for (int a = 0; a < 4; a++) {
			int rnx = rtx + dx[a], rny = rty + dy[a];
			int bnx = btx + dx[a], bny = bty + dy[a];

			//처음 가는곳이 막혀 있으면 cont
			if (map[rnx][rny] == '#') continue;

			//처음 가는곳에 파랑공이 있으면 파랑 먼저
			if (map[rnx][rny] == map[btx][bty]) {
				if (!blue_slide(bnx, bny, a)) continue;
				if (!red_slide(rnx, rny, a)) continue;
			}
			else {
				if (!red_slide(rnx, rny, a)) continue;
				if (!blue_slide(bnx, bny, a)) continue;
			}

			if (visited[rnx - dx[a]][rny - dy[a]][bnx - dx[a]][bny - dy[a]]) continue;

			rq.push(make_tuple(rnx - dx[a], rny - dy[a], answer));
			bq.push(make_pair(bnx - dx[a], bny - dy[a]));
			visited[rnx - dx[a]][rny - dy[a]][bnx - dx[a]][bny - dy[a]] = 1;

			if (answer >= 10) fail = true;
			if (done || fail) break;
		}

		if (done || fail) break;
	}

	if (fail) answer = -1;
	cout << answer;

	return 0;
}