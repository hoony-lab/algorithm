#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
using namespace std;
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };

struct FISH { int x, y, d; };

int a, b, max_fish_sum = 0, init_map[4][4];

void print(int map[][4]) {
	F(x, 4) {
		F(y, 4) {
			cout << map[x][y] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void print(int map[][4], FISH fish[17]) {
	F(x, 4) {
		F(y, 4) {
			if(map[x][y]) cout << map[x][y] << "," << fish[map[x][y]].d << "\t";
			else  cout << "0\t";
		}
		cout << '\n';
	}
	cout << '\n';
}
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= 4 || y >= 4);
}

void fish_move(FISH fish[17], FISH shark, int map[][4]) {

	for(int i = 1 ; i < 17 ; ++i) if (check(fish[i].x, fish[i].y) && map[fish[i].x][fish[i].y]) {
		int tx = fish[i].x, ty = fish[i].y, td = fish[i].d;

		F(a, 8) {
			int nd = (a + td) % 8;
			int nx = tx + dx[nd], ny = ty + dy[nd], new_fish_num;

			//cout << i << " >> " << map[nx][ny] << '\n';
			if (!check(nx, ny) || (shark.x == nx && shark.y == ny)) continue;
			new_fish_num = map[nx][ny];

			//cout << "\t" << i << " >> " << map[nx][ny] << '\n';

			if (new_fish_num) {
				fish[i] = { nx, ny, nd };
				fish[new_fish_num] = {tx, ty, fish[new_fish_num].d };
				//cout << "\t" << i << ", " << nd << " >> " << map[nx][ny] << ", " << fish[new_fish_num].d <<  '\n';
				//cout << "\t!!" << fish[i].x << ", " << fish[i].y << ", " << fish[i].d << '\n';
			}
			else {
				fish[i] = { nx, ny, nd};
				//cout << "\t" << i << " >> " << "dead" << '\n';
			}

			swap(map[tx][ty], map[nx][ny]);
			break;
		}
	}
}
void shark_move_and_eat(FISH fish[17], FISH shark, int map[][4]) {
	
}
void dfs(FISH fish[17], FISH shark, int map[][4], int sum) {

	//cout << "\t\t" << max_fish_sum << " : " << sum << '\n';
	max_fish_sum = max(max_fish_sum, sum);

	// 물고기 움직임
	fish_move(fish, shark, map);
	//cout << " after fish move\n";
	//print(map, fish);

	// 상어가 먹기전 위치와 방향
	//cout << "shark : " << shark.x << ", " << shark.y << " : " << shark.d << '\n';

	// 상어의 방향으로 1, 2, 3 칸 전진한 경우
	for (int i = 1; i <= 3; ++i) {
		int new_map[4][4]{}; FISH new_fish[17], new_shark;
		memcpy(new_map, map, sizeof(new_map)); memcpy(new_fish, fish, sizeof(new_fish)); new_shark = shark;

		new_shark.x = shark.x + dx[shark.d] * i, new_shark.y = shark.y + dy[shark.d] * i;

		// 상어가 외벽으로 가거나, 움직일 자리에 물고기가 없으면 PAAS
		if (!check(new_shark.x, new_shark.y) || !new_map[new_shark.x][new_shark.y]) continue;

		// shark_move_and_eat
		// 0. 상어가 먹은 물고기 번호 저장
		// 1. 상어가 물고기를 먹고 상어정보 = 물고기 정보
		// 2. 있던 물고기 정보는 0
		// 3. 있던 물고기 자리도 0
		//sum += new_map[new_shark.x][new_shark.y];
		int eaten_fish_num = new_map[new_shark.x][new_shark.y];
		new_shark.d = new_fish[eaten_fish_num].d;
		new_fish[eaten_fish_num] = { -1, -1, -1 };
		new_map[new_shark.x][new_shark.y] = 0;

		//cout << "new_shark : " << new_shark.x << ", " << new_shark.y << " : " << new_shark.d << '\n';
		//print(new_map, new_fish);

		dfs(new_fish, new_shark, new_map, sum + eaten_fish_num);
	}
}
int main() {
	FISH fish[17], shark;

	fish[0] = { -1,-1,-1 };
	F(x, 4) F(y, 4) {
		cin >> a >> b;
		init_map[x][y] = a;
		fish[a] = { x, y, b - 1 };
	}

	//max_fish_sum += init_map[0][0];
	// 0. 상어가 먹은 물고기 번호 저장
	// 1. 상어가 물고기를 먹고 상어정보 = 물고기 정보
	// 2. 있던 물고기 정보는 0
	// 3. 있던 물고기 자리도 0
	int eaten_fish_num = init_map[0][0];
	shark = fish[eaten_fish_num];
	fish[eaten_fish_num] = {-1, -1, -1};
	init_map[0][0] = 0;

	dfs(fish, shark, init_map, eaten_fish_num);

	cout << max_fish_sum;
	return 0;
}