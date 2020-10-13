#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 101
// x, y 상어 위치 / s 속력 / d 이동 방향 / z 크기
struct SHARK { int x, y, s, d, z, idx; };
vector<SHARK> shark, moved_shark;
// 위 아래 오른 왼
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int xxx, yyy, m, rr, cc, ss, dd, zz, king = -1, ans;
vector<int> map[MAX][MAX];

// 칸이 격자판의 경계를 넘는 경우에는 방향을 반대로 바꿔서 속력을 유지한채로 이동한다.
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= xxx || y >= yyy);
}
// 낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.

// 낚시왕이 오른쪽으로 한 칸 이동한다.
// 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다.상어를 잡으면 격자판에서 잡은 상어가 사라진다.
// 상어가 이동한다.

void print() {
	for (SHARK s : shark)
		cout << s.idx << " : " << s.x << ", " << s.y << '\n';
	cout << '\n';
}
void init() {
	cin >> xxx >> yyy >> m;
	//shark.resize(m);
	F(i, m) {
		cin >> rr >> cc >> ss >> dd >> zz;
		shark.push_back({ rr - 1, cc - 1, ss, dd - 1, zz, i });
		map[rr - 1][cc - 1].push_back(i);
	}
}

void find_catch_shark (int king) {
	int x = 0;
	while (check(x, king)) {
		if (map[x][king].size()) break;
		else x++;
	}

	// 못 찾았을 때 아무것도 안함
	if (!check(x, king)) return;

	// 찻았을 때 어떤 상어 번호인지 탐색
	F(i, (int)shark.size()) {
		if (shark[i].x == x && shark[i].y == king) {
			//cout << "AT : " << x << ", " << king << '\n';
			//cout << "idx : " << shark[i].idx << " ::: " << shark[i].z << " = " << ans << '\n';
			ans += shark[i].z;
			map[shark[i].x][shark[i].y].clear();
			shark.erase(shark.begin() + i);
			break;
		}
	}
}

void move_shark() {

	F(i, (int)shark.size()) {
		int x = shark[i].x, y = shark[i].y;
		map[x][y].clear();
	}

	F(i, (int)shark.size()) {
		int x = shark[i].x, y = shark[i].y;
		//cout << "MOVE : " << x << ", " << y << '\n';
		// 위 아래
		if (shark[i].d < 2) {
			int move_cnt = shark[i].s % (xxx * 2 - 2);
			while (move_cnt--) {
				if (!check(x + dx[shark[i].d], y))
					shark[i].d = (shark[i].d + 1) % 2;
				x += dx[shark[i].d];
			}
		}
		// 좌 우
		else {
			int move_cnt = shark[i].s % (yyy * 2 - 2);
			while (move_cnt--) {
				if (!check(x, y + dy[shark[i].d] ))
					shark[i].d = (shark[i].d + 1) % 2 + 2;
				y += dy[shark[i].d];
			}
		}
		shark[i].x = x;
		shark[i].y = y;
		// shark[i].s, shark[i].d, shark[i].z
		map[x][y].push_back(shark[i].idx);
	}
}

bool cmp(int a, int b) {
	int aa, bb;
	F(i, (int)shark.size()) {
		if (shark[i].idx == a)		aa = shark[i].z;
		if (shark[i].idx == b)		bb = shark[i].z;
	}
	return aa > bb;
}

void eat_shark() {
	F(x, xxx) F(y, yyy) {
		int map_size = (int)map[x][y].size();
		if (map_size > 1) {
			//cout << "CHECKING : " << x << ", " << y << '\n';
			sort(map[x][y].begin(), map[x][y].end(), cmp);
			int max_shark_idx = map[x][y][0];

			for(int i = map_size - 1 ; i >= 0 ; --i) {
				if (i == 0) continue;
				//cout << "EAT : " << max_shark_idx << " > " << map[x][y][i] << '\n';

				int aa;
				F(j, (int)shark.size()) {
					if (shark[j].idx == map[x][y][i]) {
						aa = j;
						break;
					}
				}
				shark.erase(shark.begin() + aa);
			}

			map[x][y].clear();
			map[x][y].push_back(max_shark_idx);
		}
	}
}

int main() {
	init();
	F(i, yyy) {
		//cout << "# KING at : " << i << '\n';
		if (shark.size() == 0) break;
		find_catch_shark(i);
		move_shark();
		eat_shark();
	}
	cout << ans;

	return 0;
}