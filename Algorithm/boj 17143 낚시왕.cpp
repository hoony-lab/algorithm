/*
20201011 1900
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 101
// x, y 상어 위치 / s 속력 / d 이동 방향 / z 크기
struct SHARK { int x, y, s, d, z, idx; };
vector<SHARK> shark;
// 위 아래 오른 왼
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int xxx, yyy, m, rr, cc, ss, dd, zz, king = -1;
vector<int> map[MAX][MAX];

// 칸이 격자판의 경계를 넘는 경우에는 방향을 반대로 바꿔서 속력을 유지한채로 이동한다.
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= xxx || y >= yyy);
}
// 낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.

// 낚시왕이 오른쪽으로 한 칸 이동한다.
// 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다.상어를 잡으면 격자판에서 잡은 상어가 사라진다.
// 상어가 이동한다.

void init() {
	cin >> xxx >> yyy >> m;
	shark.resize(m);
	F(i, m) {
		cin >> rr >> cc >> ss >> dd >> zz;
		shark.push_back({ rr - 1, cc - 1, ss, dd - 1, zz });
		map[rr - 1][cc - 1].push_back(i + 1);				// i 번째 인덱스 >> i + 1로 표현
	}
}

void move_king() {
	king++;
}

void find_catch_shark () {
	int x = 0, idx;
	while (check(x, king)) {
		if (map[x][king].front()) break;
		else x++;
	}

	// 못 찾았을 때 아무것도 안함
	if (!check(x, king)) return;

	// 찻았을 때 어떤 상어 번호인지 탐색
	F(i, (int)shark.size()) {
		if (shark[i].x == x && shark[i].y == king) {
			idx = i; break;
		}
	}

	map[shark[idx].x][shark[idx].y].clear();
	shark.erase(shark.begin() + idx);
}

void move_shark() {

}

bool cmp(int a, int b) {
	return shark[shark[a].idx].s > shark[shark[b].idx].s;
}

void eat_shark() {
	// ?
	F(x, xxx) F(y, yyy) {
		if (map[x][y].size() > 1) {

			sort(map[x][y].begin(), map[x][y].end(), cmp);
			 v
			int max_shark_idx = map[x][y].front();
			map[x][y].clear();
			map[x][y].push_back(max_shark_idx);
		}
	}

	
}

int main() {
	init();

	F(i, yyy) {
		move_king();
		find_catch_shark();
		move_shark();
		eat_shark();
	}
	return 0;
}