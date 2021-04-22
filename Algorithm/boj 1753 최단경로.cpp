#include <iostream>
#include <vector>
#include <queue>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define FS(s, i, n) for(int i = s ; i < n ; ++i)
using namespace std;
struct UD { int u, d; };
struct DU { int d, u; };

int V, e, start, u, v, d, dist[20001], visit[20001];
vector<UD> map[20001];

int main() {
	cin >> V >> e >> start;
	F(i, e) cin >> u >> v >> d, map[u].push_back({v, d});

	F(i, V + 1) dist[i] = 1e9;

	// dijkstra(start)
	dist[start] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push({ 0, start });
	
	while (!pq.empty()) {
		// 현재점, 짧은것이 먼저 오도록 음수화
		int td = -pq.top().first;
		int te = pq.top().second;
		pq.pop();

		// 최단 거리가 아니면 스킵
		if (td > dist[te]) continue;

		F(i, (int)map[te].size()) {
			int nd = td + map[te][i].d;
			int ne = map[te][i].u;

			if (nd < dist[ne]) {
				dist[ne] = nd;
				pq.push({ -nd, ne});
			}
		}
	}

	FS(1, i, V + 1) {
		if (dist[i] == 1e9) cout << "INF\n";
		else cout << dist[i] << '\n';
	}

	return 0;
}