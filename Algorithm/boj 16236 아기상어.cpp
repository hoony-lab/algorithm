#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
#define F(i,n) for(int i=0;i<n;++i)
#define MAX 21
struct FISH { int x, y, dist; };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1};

// 가장 처음에 아기 상어의 크기는 2
int baby_size = 2, feed, yy, xx, ans;
int n, map[MAX][MAX], visit[MAX][MAX];
vector<FISH> v;
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}
bool comp(FISH f1, FISH f2) {
	if (f1.dist < f2.dist)
		return true;

	if (f1.dist == f2.dist) {
		if (f1.x == f2.x) {
			return f1.y < f2.y;
		}
		return f1.x < f2.x;
	}
	return false;
}

void eat_fish() {
	// 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
	//	거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
	//	거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
	sort(v.begin(), v.end(), comp);
	// 지도에 먹음 표시
	map[v.front().x][v.front().y] = 0;
	// 생선까지 걸린 시간
	ans += v.front().dist;
	// 아기 상어가 먹을 수 있는 물고기가 있는 칸으로 이동
	xx = v.front().x, yy = v.front().y;

	//cout << "ERASE_FISH : " << v.front().x << ", " << v.front().y << " : " << v.front().dist << " , ANS : " << ans << '\n';
	// 물고기를 먹으면, 그 칸은 빈 칸이 된다.
	v.erase(v.begin());

	// 아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가
	if (++feed == baby_size) {
		baby_size++;
		//cout << "SIZE UP SIZE UP SIZE UP: " << baby_size << '\n';
		// 경험치 초기화
		feed = 0;
	}
}

void baby_to_fish_dist() {
	v.clear();

	int visit[MAX][MAX]{};
	queue<FISH> q;
	q.push({ xx, yy, 1 });
	visit[xx][yy] = 1;

	int find_first_fish_dist = MAX * MAX;
	while (!q.empty()) {
		int tx = q.front().x, ty = q.front().y, tdist = q.front().dist;
		q.pop();
		//if (find_first_fish_dist > tdist) continue;
		//cout << "search : " << tx << ", " << ty << " / " << tdist << '\n';
		F(a, 4) {
			int nx = tx + dx[a], ny = ty + dy[a];
		
			if (!check(nx, ny) || baby_size < map[nx][ny] || visit[nx][ny] || find_first_fish_dist < visit[tx][ty]) continue;

			q.push({ nx, ny, visit[tx][ty] });
			visit[nx][ny] = visit[tx][ty] + 1;

			//cout << "!!PUSH!! : " << nx << ", " << ny << '\n';

			// 거리가 같은물고기
			if (map[nx][ny] != 0 && baby_size > map[nx][ny]) {
				v.push_back({ nx, ny, visit[nx][ny] - 1 });
				find_first_fish_dist = visit[nx][ny] - 1;
			} 
		}
	}
}

int main() {
	cin >> n;
	F(x, n) F(y, n) {
		cin >> map[x][y];
		if (map[x][y] && map[x][y] != 9) v.push_back({ x,y, -1 });
		if (map[x][y] == 9) xx = x, yy = y, map[x][y] = 0;
	}

	while(1){
		baby_to_fish_dist();

		if (v.empty()) break;
		//cout << "SAME_FISH_CNT : " << v.size() << " / FISH_DIST : " <<  v.front().dist << '\n';
		//for (FISH f : v)cout << f.x << ", " << f.y << " : " << f.dist << '\n';
		
		eat_fish();
	}

	cout << ans;
	return 0;
}
/*
6
5 4 3 2 3 4
4 3 2 3 4 5
3 2 9 5 6 6
2 0 0 3 4 5
3 2 0 6 5 4
6 6 6 6 6 6

>> 60
*/