#include <iostream>
#include <queue>
#include <vector>
#define F(i,n) for(int i = 0 ; i < n ; ++i)
#define MAX 1001
using namespace std;

int n, m, party, home, u, v, t, road[MAX][MAX], visit[MAX], time[MAX], go_max_time, back_max_time;
int main() {
	cin >> n >> m >> party;
	F(x, n) F(y, n) road[x][y] = 1e9;
	F(i, m) {
		cin >> u >> v >> t;
		road[u][v] = t;
	}

	// go
	F(i, n) time[i] = road[party][i];
	visit[party] = true;
	
	for (int i = 0; i < n ; ++i) {
		if (visit[party]) continue;

		int min = 1e9;
		int min_time_edge = -1;
		for (int j = 0; j < n; ++i) {
			if (visit[j]) continue;
			if (time[j] < min) {
				min = time[j];
				min_time_edge = j;
			}
		}

		visit[min_time_edge] = true;
		F(j, n) {
			if (visit[j]) continue;
			if (time[min_time_edge] + road[min_time_edge][j] < time[j])
				time[j] = time[min_time_edge] + road[min_time_edge][j];
		}
	}

	F(i, n) {
		if (time[i] != 1e9 && go_max_time < time[i]) {
			go_max_time = time[i];
			party = home;
		}
	}


	//// back
	//memset(visit, false, sizeof(visit));
	//F(i, n) time[i] = road[home][i];
	//visit[home] = true;

	//for (int i = 0; i < n; ++i) {
	//	if (visit[home]) continue;

	//	int min = 1e9;
	//	int min_time_edge = -1;
	//	for (int j = 0; j < n; ++i) {
	//		if (visit[j]) continue;
	//		if (time[j] < min) {
	//			min = time[j];
	//			min_time_edge = j;
	//		}
	//	}

	//	visit[min_time_edge] = true;
	//	F(j, n) {
	//		if (visit[j]) continue;
	//		if (time[min_time_edge] + road[min_time_edge][j] < time[j])
	//			time[j] = time[min_time_edge] + road[min_time_edge][j];
	//	}
	//}

	//back_max_time = time[home];

	cout << go_max_time + back_max_time;
	return 0;
}