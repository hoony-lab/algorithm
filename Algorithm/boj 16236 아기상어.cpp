//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <memory.h>
//using namespace std;

//int dy[] = { -1,0,0,1 };
//int dx[] = { 0,-1,1,0 };
//
///*
//
//자신보다 작은 물고기를 먹음
//먹을게없으면 엄마상어에게 도움
//1마리보다 많으면 가장 가까운물고기 / 그중 위에있는 / 그중 왼쪽에있는
//지나가야하는 칸의 최솟값
//먹는데 시간은 안걸림 / 먹으면 빈칸
//자신의크기 갯수만큼 먹어야 크기증가
//
//	for (int y = 0; y < N; ++y)	{
//		for (int x = 0; x < N; ++x) {
//
//		}
//	}
//
//
//*/
//int answer;
//int N, shark, feed, hunt[8] = { 0, }, yy, xx;
//int map[21][21], visit[21][21];
//queue<pair<int, int>> q;
//
//void print() {
//	for (int y = 0; y < N; ++y)	{
//		for (int x = 0; x < N; ++x) {
//			//cout << map[y][x] << " ";
//			cout << visit[y][x] << " ";
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//}
//
//int main() {
//
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	answer = 0;
//	shark = feed = 2;
//	memset(visit, 0, sizeof(visit));
//
//	for (int y = 0; y < N; y++) {
//		for (int x = 0; x < N; x++) {
//			cin >> map[y][x];
//			if (map[y][x] == 9) {
//				q.push({ y,x });
//				visit[y][x] = 1;
//				map[y][x] = 0;
//			}
//			hunt[map[y][x]]++;
//		}
//	}
//
//	if (hunt[1] == 0){
//		cout << answer; 
//
//		return answer;
//	}
//
//	bool no_more_hunt = false;
//
//	while (!q.empty()) {
//		int ty = q.front().first;
//		int tx = q.front().second;
//		q.pop();
//		cout << "CHEKKING " << ty << ", " << tx << '\n';
//
//		for (int a = 0; a < 4; a++){
//			int ny = ty + dy[a];
//			int nx = tx + dx[a];
//
//			if (ny < 0 || nx < 0 || ny >= N || nx >= N || visit[ny][nx] > 0 || map[ny][nx] > shark) continue;
//			cout << ny << " ," << nx << '\n';
//
//			if (map[ny][nx] == 0 || map[ny][nx] == shark) {
//				q.push({ ny,nx });
//				visit[ny][nx] = visit[ty][tx] + 1;
//			}
//			//상어보다 몸집이 작으면 냠냠 하고 재탐색
//			else if (map[ny][nx] < shark) {
//				while(!q.empty())	q.pop();
//
//				print();
//				cout << q.size() << ", " << ny << ", " << nx << '\n';
//
//				answer += visit[ty][tx];
//				
//				//hunt[map[ny][nx]]--;
//				map[ny][nx] = 0;
//
//				//더이상 먹을게 없을때 중간 가지치기
//				/*
//				for (int i = 1; i < shark; i++)
//				{
//					if(hunt[i] < feed) no_more_hunt = true;
//				}
//				*/
//
//
//				q.push({ ny,nx });
//				memset(visit, 0, sizeof(visit));
//				visit[ny][nx] = 1;
//
//				//자기 몸집만큼 먹으면 상어 성장
//				if (--feed == 0) feed = ++shark;
//				break;
//			}
//
//
//		}
//
//
//		if (no_more_hunt) break;
//		else {
//
//		}
//
//	}
//
//	cout << answer;
//
//	
//
//	return answer;
//
//	//for (int y = 0; y < N; ++y)	{
//	//	for (int x = 0; x < N; ++x) {
//	//		if (map[y][x] < shark)
//	//			
//	//	}
//	//}
//
//}

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

int ans;
int n, map[MAX][MAX], visit[MAX][MAX];
int baby_size = 2, feed, yy, xx;
queue<pair<int, int>> q;
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

void baby_to_fish_dist() {
	int visit[MAX][MAX]{};
	queue<FISH> q;
	q.push({ xx, yy });
	visit[xx][yy] = 1;

	while (!q.empty()) {
		int tx = q.front().x, ty = q.front().y;
		q.pop();

		F(i, (int)v.size()) 
			if (v[i].x == tx && v[i].y == ty) 
				v[i].dist = visit[tx][ty] - 1;
		
		F(a, 4) {
			int nx = tx + dx[a], ny = ty + dy[a];
			if (!check(nx, ny) || baby_size < map[nx][ny]) continue;
			q.push({ nx, ny, });
			visit[nx][ny] = visit[tx][ty] + 1;
		}
	}
	
}

int main() {
	cin >> n; 
	F(x, n) F(y, n) {
		cin >> map[x][y];
		if (map[x][y] && map[x][y] != 9) v.push_back({ x,y,-1 });
		if (map[x][y] == 9) xx = x, yy = y;
	}

	if (v.size() == 0) return 0;
	return 0;
}