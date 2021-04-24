// 20210424 1602 - 1729
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 101
#define FIND_HOLE 0
#define FIND_BLUE 1
#define FIND_RED 2
#define FIND_NOTHING 3
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct PRB {
	int rx, ry, bx, by, cnt;
	char map[MAX][MAX]{};
};
struct P { int x, y; };
int n, m;
char map[MAX][MAX], visit[MAX][MAX];
P red, blue, hole;

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= m);
}
void print(int ma[][MAX]) {
	F(x, n) {
		F(y, m) {
			cout << ma[x][y] << " ";
		}cout << '\n';
	}
}
int check_red_way(P r, P b, int dir, int ma[][MAX]) {
	int nx = r.x, ny = r.y;
	do {
		nx += dx[dir], ny += dy[dir];
		if (nx == hole.x && ny == hole.y) return FIND_HOLE;
		else if (nx == b.x && ny == b.y) return FIND_BLUE;
		//else if (nx == r.x && ny == r.y) return FIND_RED;
	} while (ma[nx][ny] == '.');

	return FIND_NOTHING;
}
int check_blue_way(P r, P b, int dir, int ma[][MAX]) {
	int nx = b.x, ny = b.y;
	do {
		nx += dx[dir], ny += dy[dir];
		if (nx == hole.x && ny == hole.y) return FIND_HOLE;
		//else if (nx == b.x && ny == b.y) return FIND_BLUE;
		//else if (nx == r.x && ny == r.y) return FIND_RED;
	} while (ma[nx][ny] != '#');

	return FIND_NOTHING;
}
P roll(P p, int dir, int ma[][MAX]) {
	int nx = p.x, ny = p.y;
	do {
		nx += dx[dir], ny += dy[dir];
	} while (ma[nx][ny] == '.');

	return { nx - dx[dir], ny - dy[dir] };
}

int main() {
	cin >> n >> m;
	F(x, n) F(y, m) {
		cin >> map[x][y];

		if (map[x][y] == 'R')		red = { x, y };
		else if (map[x][y] == 'B')	blue = { x, y };
		else if (map[x][y] == 'O')	hole = { x, y };
	}

	queue<PRB> q;
	PRB tprb = { red.x, red.y, blue.x, blue.y, 0};
	memcpy(tprb.map, map, sizeof(map));
	q.push(tprb);

	while (!q.empty()) {

		int rx = q.front().rx, ry = q.front().ry, nrx = rx, nry = ry;
		int bx = q.front().bx, by = q.front().by, nbx = bx, nby = by;
		int cnt = q.front().cnt;
		int ma[MAX][MAX]{};
		memcpy(ma, q.front().map, sizeof(q.front().map));
		q.pop();

		cout << "start (" << cnt << ") : " << rx << ", " << ry << " : " << bx << ", " << by << '\n';
		print(ma);

		F(a, 4) {
			P nred, nblue;
			int red_way = check_red_way({ rx, ry }, { bx, by }, a, ma);
			int blue_way = check_blue_way({ rx, ry }, { bx, by }, a, ma);

			if (blue_way == FIND_HOLE || cnt >= 10) continue;
			else {
				if (red_way == FIND_HOLE) {
					cout << cnt + 1;
					return 0;
				}
				else if (red_way == FIND_BLUE) {
					nblue = roll({ bx, by }, a, ma);
					nred = roll({ rx, ry }, a, ma);
				}
				else if (red_way == FIND_NOTHING) {
					nred = roll({ rx, ry }, a, ma);
					nblue = roll({ bx, by }, a, ma);
				}
				else {
					cout << "WTF???????\n";
				}
			}

			if (nred.x == rx && nred.y == ry && nblue.x == bx && nblue.y == by) continue;

			ma[rx][ry] = '.', ma[bx][by] = '.';
			ma[nred.x][nred.y] = 'R', ma[nblue.x][nblue.y] = 'B';

			PRB nprb = { nred.x, nred.y, nblue.x, nblue.y, cnt + 1 };
			memcpy(nprb.map, ma, sizeof(ma));
			q.push(nprb);
		}
	}

	cout << "-1";
	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <tuple>
//#include <algorithm>
//#include <memory.h>
//using namespace std;
//
//const int dx[] = { 0,1,0,-1 };
//const int dy[] = { 1,0,-1,0 };
//
//bool fail, done;
//int n, m, rx, ry, bx, by, ans, answer;
//char map[11][11];
//int visited[11][11][11][11];
//
//bool red_slide(int &rnx, int &rny, int a) {
//
//	while (1) {
//		if (map[rnx][rny] == '#' || map[rnx][rny] == 'B') return true;
//
//		//done answer
//		if (map[rnx][rny] == 'O') {
//			done = true;
//			return true;
//		}
//
//		rnx += dx[a];
//		rny += dy[a];
//	}
//}
//
//bool blue_slide(int &bnx, int &bny, int a) {
//
//	while (1) {
//		if (map[bnx][bny] == '#' || map[bnx][bny] == 'A') return true;
//
//		//파랑공이 빠지면 안됌
//		if (map[bnx][bny] == 'O') {
//			if (done) fail = true;
//			return false;
//		}
//
//		bnx += dx[a];
//		bny += dy[a];
//	}
//}
//
//int main() {
//
//	done = false;
//	fail = false;
//	ans = 0;
//	memset(map, 0, sizeof(map));
//	memset(visited, 0, sizeof(visited));
//
//	cin >> n >> m;
//
//	for (int x = 0; x < n; ++x) {
//		for (int y = 0; y < m; ++y) {
//			cin >> map[x][y];
//			if (map[x][y] == 'R') rx = x, ry = y;
//			if (map[x][y] == 'B') bx = x, by = y;
//		}
//	}
//
//	queue<tuple<int, int, int>> rq;
//	queue<pair<int, int>> bq;
//
//	rq.push(make_tuple(rx, ry, ans));
//	bq.push(make_pair(bx, by));
//	visited[rx][ry][bx][by] = 1;
//
//	while (!rq.empty()) {
//		int rtx = get<0>(rq.front()), rty = get<1>(rq.front()), ans = get<2>(rq.front());
//		int btx = bq.front().first, bty = bq.front().second;
//		rq.pop();
//		bq.pop();
//
//		//answer = ans + 1;
//		
//
//		//std::cout << rtx << ", " << rty << " :: " << btx << ", " << bty << '\n';
//
//		for (int a = 0; a < 4; a++) {
//			int rnx = rtx + dx[a], rny = rty + dy[a];
//			int bnx = btx + dx[a], bny = bty + dy[a];
//
//			//처음 가는곳이 막혀 있으면 cont
//			if (map[rnx][rny] == '#') continue;
//
//			//처음 가는곳에 파랑공이 있으면 파랑 먼저
//			if (map[rnx][rny] == map[btx][bty]) {
//				if (!blue_slide(bnx, bny, a)) continue;
//				if (!red_slide(rnx, rny, a)) continue;
//			}
//			else {
//				if (!red_slide(rnx, rny, a)) continue;
//				if (!blue_slide(bnx, bny, a)) continue;
//			}
//
//			if (visited[rnx - dx[a]][rny - dy[a]][bnx - dx[a]][bny - dy[a]]) continue;
//
//			rq.push(make_tuple(rnx - dx[a], rny - dy[a], answer));
//			bq.push(make_pair(bnx - dx[a], bny - dy[a]));
//			visited[rnx - dx[a]][rny - dy[a]][bnx - dx[a]][bny - dy[a]] = 1;
//
//			if (answer >= 10) fail = true;
//			if (done || fail) break;
//		}
//
//		if (done || fail) break;
//	}
//
//	if (fail) answer = -1;
//	cout << answer;
//
//	return 0;
//}