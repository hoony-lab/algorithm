/*
20201011 1307

*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define F(i, n) for(int i = 0 ; i < n ;++i)
#define MAX 21
// 위 아래 왼 오
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int visit[MAX][MAX], map[MAX][MAX], smell[MAX][MAX], ss[MAX * MAX];
int _way, t[5];
int n, m, k, ans;
struct P { int x, y; };
struct SHARK { int idx, x, y, way, iway; vector<int> w[4]; };
vector<SHARK> shark, move_shark;

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}

void tic_toc() {
	F(x, n) F(y, n) if (smell[x][y]) smell[x][y]--, map[x][y] = 0;
}

bool cmp(SHARK s1, SHARK s2) {
	int x1 = s1.x, y1 = s1.y, x2 = s2.x, y2 = s2.y;

	// 둘다 빈칸 || 둘다 냄새칸
	if ((map[x1][y1] == 0 && map[x2][y2] == 0) || map[x1][y1] != 0 && map[x2][y2] != 0)
		return s1.iway < s2.iway;

	//  둘중 하나 빈칸
	if (map[x1][y1] == 0 || map[x2][y2] == 0)
		return map[x1][y1] == 0;
}

void move() {

}

void cal_move() {
	int ssize = (int)shark.size();
	cout << "SHARK_SIZE : " << ssize << '\n';

	F(i, ssize) {
		bool done = false;
		int tx = shark[i].x, ty = shark[i].y, tway = shark[i].way;

		vector<SHARK> possible_shark(1);

		int iway = 0;
		for (int nway : shark[i].w[tway]) {
			int nx = tx + dx[nway], ny = ty + dx[nway];

			if (!check(nx, ny) || (map[nx][ny] != 0 && map[nx][ny] != i)) continue;

			// 빈 칸, 탐색 중지 (최우선 순위)
			if (map[nx][ny] == 0) {
				possible_shark.push_back({ shark[i].idx, nx, ny, tway, iway });
				break;
			}

			// 자기 냄새 칸, 계속 탐색 (차선책)
			if (map[nx][ny] == i) {
				possible_shark.push_back({ shark[i].idx, nx, ny, tway, iway });
			}

			iway++;
		}

		// 가장 앞의 상어가 최우선 순위 상어
		sort(possible_shark.begin(), possible_shark.end(), cmp);

		// 다른칸에 이동 못했으면
		if (possible_shark.size() == 0) {
			shark.erase(shark.begin() + shark[i].idx);
			continue;
		}
		
	}

	
	move_shark.clear();
	move_shark.push_back();
	smell[nx][ny] = k + 1;
	map[nx][ny] = i;
	 
	// 전체 냄새 감소
	tic_toc();
}

void init() {
	cin >> n >> m >> k;
	shark.resize(m);
	F(x, n) F(y, n) {
		cin >> map[x][y];
		if (map[x][y]) {
			smell[x][y] = k;
			shark[map[x][y] - 1].x = x, shark[map[x][y] - 1].y = y;
			shark[map[x][y] - 1].idx = map[x][y] - 1;
		}
	}
	F(i, m) cin >> shark[i].way, shark[i].way--;	// 현재 상어 방향
	F(i, m) {			// 상어 번호
		F(a, 4) {		// 방향 번호
			F(aa, 4) {	// 각 방향
				cin >> t[aa];
				shark[i].w[aa].push_back(t[aa] - 1);
			}
		}
	}
}
int main() {
	init();

	//do {
	//	tik_toc();
	//} while (1);
	do {
		// 시간 추가
		if (++ans > 1000) {
			cout << -1;
			return 0;
		}

		cal_move();
		move();
		

	} while (shark.size() > 1);

	cout << ans;
	return 0;
}
/*
5 4 4
0 0 0 0 3
0 2 0 0 0
1 0 0 0 4
0 0 0 0 0
0 0 0 0 0

4 4 3 1

2 3 1 4
4 1 2 3
3 4 2 1
4 3 1 2

2 4 3 1
2 1 3 4
3 4 1 2
4 1 2 3

4 3 2 1
1 4 3 2
1 3 2 4
3 2 1 4

3 4 1 2
3 2 4 1
1 4 2 3
1 4 2 3
*/