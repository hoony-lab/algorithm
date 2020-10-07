#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 21

struct PASSENGER { int px, py, pxx, pyy, passenger_dest, passenger_taxi; };
struct P { int x, y; };

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int map[MAX][MAX];
int n, m, fuel, taxi_x, taxi_y, px, py, pxx, pyy, ans, done[MAX], done_cnt;

vector<PASSENGER> v;

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}

// 승객 - 목적지, 택시 거리
void cal_passenger_dest_taxi_dist() {

	F(i, (int)v.size()) {
		if (done[i]) continue;

		int x = v[i].px, y = v[i].py;
		int visit[MAX][MAX]{};

		queue<P> q;
		q.push({ x, y });
		visit[x][y] = 1;
		// 일단 못가는 걸로 가정
		v[i].passenger_taxi = -1;
		v[i].passenger_dest = -1;


		while (!q.empty()) {
			int tx = q.front().x, ty = q.front().y;
			q.pop();

			// 택시 도착 후 거리 저장
			// 택시와 승객이 같은 위치에 서 있으면 그 승객까지의 최단거리는 0
			if (tx == taxi_x && ty == taxi_y) 
				v[i].passenger_taxi = visit[tx][ty] - 1;

			// 목적지 도착 후 거리 저장
 			if (tx == v[i].pxx && ty == v[i].pyy)
				v[i].passenger_dest = visit[tx][ty] - 1;

			F(a, 4) {
				int nx = tx + dx[a], ny = ty + dy[a];
				if (!check(nx, ny) || visit[nx][ny] || map[nx][ny]) continue;
				
				q.push({ nx, ny });
				visit[nx][ny] = visit[tx][ty] + 1;
			}
		}
		cout << x << ", " << y << " : " << v[i].passenger_taxi << ", " << v[i].passenger_dest << '\n';
	}

}

/// 택시 - 승객들 거리
// 현재 위치에서 최단거리가 가장 짧은 승객을
// 그중 행 번호가 가장 작은 승객을
// 그중 열 번호가 가장 작은 승객을
int min_taxi_passenger_dist_idx() {
	int min_passenger_taxi_dist = 1e9;
	int min_passenger_taxi_idx = MAX;
	int invalid_cnt = 0;

	F(i, (int)v.size()) {
		if (done[i]) continue;
		if (v[i].passenger_dest == -1) {
			invalid_cnt++; continue;
		}

		if (min_passenger_taxi_dist > v[i].passenger_taxi) {
			min_passenger_taxi_dist = v[i].passenger_taxi;
			min_passenger_taxi_idx = i;
		}
		else if (min_passenger_taxi_dist == v[i].passenger_taxi) {
			if (v[min_passenger_taxi_idx].px == v[i].px) {
				if (v[min_passenger_taxi_idx].py > v[i].py) {
					min_passenger_taxi_dist = v[i].passenger_taxi;
					min_passenger_taxi_idx = i;
				}
			}
			else if (v[min_passenger_taxi_idx].px > v[i].px) {
				min_passenger_taxi_dist = v[i].passenger_taxi;
				min_passenger_taxi_idx = i;
			}
		}
	}

	if (invalid_cnt == m - done_cnt || 
			v[min_passenger_taxi_idx].passenger_taxi > fuel ||
			v[min_passenger_taxi_idx].passenger_dest + v[min_passenger_taxi_idx].passenger_taxi > fuel)
		return MAX;
	else {
		done[min_passenger_taxi_idx] = true;
		done_cnt++;
		taxi_x = v[min_passenger_taxi_idx].pxx;
		taxi_y = v[min_passenger_taxi_idx].pyy;

		cout << "pick : " << min_passenger_taxi_idx << '\n';
		return min_passenger_taxi_idx;
	}
}

// 입력
void init() {
	cin >> n >> m >> fuel;
	F(x, n) F(y, n) cin >> map[x][y];
	cin >> taxi_x >> taxi_y; taxi_x--, taxi_y--;
	F(i, m) {
		cin >> px >> py >> pxx >> pyy;
		v.push_back({ px - 1, py - 1, pxx - 1, pyy - 1 });
	}
}

int main() {

	init();

	while (done_cnt != m) {
		
		cout << "done_cnt : " << done_cnt << " : start : " << taxi_x << ", " << taxi_y << " / " << fuel << '\n';

		cal_passenger_dest_taxi_dist();

		int idx = min_taxi_passenger_dist_idx();

		// 승객이 하나라도 목적지에 도달 못하면 || 남은 연료보다 거리가 멀면
		if (idx == MAX) {
			cout << -1;
			return 0;
		}

		// 연료는 한 칸 이동할 때마다 1만큼 소모
		// 한 승객을 목적지로 성공적으로 이동 > 소모한 연료 양의 두 배가 충전
		fuel = fuel - v[idx].passenger_taxi + v[idx].passenger_dest;
	}
	
	cout << fuel;
 	return 0;
}
/*
6 3 100
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 1 0 0
0 0 0 0 1 0
0 0 0 1 0 0
1 2
2 2 2 2
3 2 3 2
4 2 4 2

>> 97

6 4 100
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 1 0 0
0 0 0 0 1 0
0 0 0 1 0 0
6 5
2 2 5 6
5 4 1 6
3 6 1 1
4 6 1 6

>> -1

6 4 15
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 1 0
0 0 0 1 0 0
6 5
2 2 5 6
5 4 1 6
4 2 3 5
1 6 5 4

>> 20

//6 4 100
//0 0 1 0 0 0
//0 0 1 0 0 0
//0 0 0 0 0 0
//0 0 0 0 0 0
//0 0 0 0 1 0
//0 0 0 1 0 0
//6 5
//1 6 2 2		-6 +7
//1 6 3 5		-7 +3
//1 6 5 4		-3 +6
//1 6 1 1		-6 +9
//
//>> -1
*/