#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define F(i, n, m) for(int i = m ; i < n ; ++i)
#define MAX 5
struct FISH { int x, y, way, idx; };
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};
int ans;
int map[MAX][MAX], dead_fish[MAX * MAX];
FISH fish[MAX * MAX];
FISH shark;

void print(int m[][MAX], FISH f[], int d[], FISH s) {
	cout << "dead fish  \n";
	F(i, MAX * MAX, 0) if (d[i]) cout << i << " = " << f[i].idx << ", way : " << f[i].way << "\n";
		cout << '\n';
	F(x, 4, 0) {
		F(y, 4, 0) {
			cout << m[x][y] << ' ';
		}cout << '\n';
	}cout << "\n\n";
}
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= 4 || y >= 4);
}
void init() {
	F(i, 16, 0) {
		int idx, way;
		cin >> idx >> way;
		fish[idx - 1] = { i / 4, i % 4, way - 1, idx - 1 };
		map[i / 4][i % 4] = idx - 1;
		// cout << fish[idx - 1].x << ", " << fish[idx - 1].y << ", " << " : " << fish[idx - 1].idx << ", " << fish[idx - 1].way << '\n';
	}
}

// 청소년 상어는 (0, 0)에 있는 물고기를 먹고, (0, 0)에 들어가게 된다.
// 상어의 방향은 (0, 0)에 있던 물고기의 방향과 같다. 이후 물고기가 이동한다.
void eat_fish(int m[MAX][MAX], FISH f[MAX*MAX], int d[MAX*MAX], FISH s, int x, int y) {
	s = { x, y, f[m[x][y]].way };
	d[m[x][y]] = true;
	//ans += map[nx][ny];
	m[x][y] = -1;
}
void revive_fish(int m[MAX][MAX], FISH f[], int d[], FISH s, int x, int y, int nx, int ny, int way, int idx) {
	m[nx][ny] = idx;
	//ans -= map[nx][ny];
	d[m[nx][ny]] = false;
	s = { x, y, way };
}

void move_fish(int m[][MAX], FISH f[], int d[], FISH s) {
	F(i, 16, 0) {
		if (d[i]) continue;
		int tx = f[i].x, ty = f[i].y, tway = f[i].way, tidx = f[i].idx;
		
		// 이동할 수 있는 칸을 향할 때까지 방향을 45도 반시계 회전
		F(a, 8, 0) {
			int nway = (tway + a) % 8;
			int nx = tx + dx[nway], ny = ty + dx[nway];

			//  이동할 수 없는 칸은 상어가 있거나, 공간의 경계를 넘는 칸이다
			if(!check(nx, ny) || (shark.x == nx && shark.y == ny)) continue;
			
			// 물고기가 다른 물고기가 있는 칸으로 이동할 때는 서로의 위치를 바꾸는 방식으로 이동
			int nidx = m[nx][ny];

			//swap(fish[tidx], fish[nidx]);

			f[tidx] = f[nidx];
			f[nidx] = { tidx, nway, tx, ty };
			cout << "swap : " << tidx << " >> " << nidx << '\n';
			break;
		}
	}
}

void dfs(int m[][MAX], FISH f[], int d[], FISH s, int x, int y, int way, int idx, int sum) {
	// 상어가 물고기 먹기
	sum += m[x][y] + 1;
	eat_fish(m, f, d, s, x, y);
	
	// 물고기 움직이기
	move_fish(m, f, d, s);

	print(m, f, d, s);

	// 상어 움직이기 (최대 3칸까지 이동 가능)
	F(a, 4, 1) {
		int nx = x + dx[way] * a, ny = y + dy[way] * a;
		if (!check(nx, ny)) break;

		// 물고기가 있으면 
		if (m[nx][ny] >= 0) {
			int nway = f[m[nx][ny]].way, nidx = m[nx][ny];

			cout << "new place : " << nx << ", " << ny << ", nway : " <<  nway << '\n';
			dfs(m, f, d, s, nx, ny, nway, nidx, sum);
		}
	}
	
	ans = max(ans, sum);
}

int main() {

	init();

	// 상어가 물고기 먹기 > 물고기 움직이기 > 상어 움직이기
	dfs(map, fish, dead_fish, shark, 0, 0, fish[map[0][0]].way, map[0][0], 0);

	cout << ans;
	return 0;
}