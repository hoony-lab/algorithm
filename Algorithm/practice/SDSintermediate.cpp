#include "SDSintermediate.h"
using namespace std;

//memory overflow
void SDSintermediate::q1753()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	//input
	int v, e, start;
	cin >> v >> e >> start;

	// x,y,w in vec
	vector<pair<int,int>> vec[20001];
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back(make_pair(v, w));
	}
	
	//bfs, accumulate each edge
	int visited[20001];
	for (int i = 1; i < v; i++) {
		visited[i] = 987654321;
	}

	visited[start] = 0;

	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int tx = q.front();
		q.pop();
		sort(vec[tx].begin(), vec[tx].end());

		int size = vec[tx].size();
		for (int i = 0; i < size; i++) {
			int ny = vec[tx].at(i).first;
			int nw = vec[tx].at(i).second;
			cout << "checking : " << tx << ", " << ny << ", " << nw << '\n';
			if (!visited[ny]) {
				visited[ny] = visited[tx] + nw;
				q.push(ny);
			}
			else if (visited[ny]) {
				visited[ny] = min(visited[tx] + nw, visited[ny]);
				q.push(ny);
			}
		}
	}



	


	////answer
	//sort(vec[start].begin(), vec[start].end());

	//for (int i = 1; i <= v; i++) {
	//	int size = vec[start].size();
	//	int result = 0;
	//	bool invalid = false;

	//	for (int j = 0; j < size; j++) {
	//		if (vec[start].at(j).first < i) continue;
	//		if (vec[start].at(j).first > i) {
	//			invalid = true; break;
	//		}
	//		if (vec[start].at(j).first == i) {
	//			result = vec[start].at(j).second;	break;
	//		}
	//	}
	//	if (invalid)	cout << "INF" << "\n";
	//	else			cout << result << '\n';
	//}

	for (int i = 1; i <= v; i++) {
		if (i == 1) {
			cout << 0 << '\n'; continue;
		}
		if (visited[i] < 98765431 && 0< visited[i]) cout << visited[i] << '\n';
		else cout << "INF" << '\n';
	}
	



	/*

5 6
1
5 1 1
1 2 3
1 2 2
2 3 4
2 4 5
3 4 6
	*/
}

void SDSintermediate::q1911()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n, l;
	cin >> n >> l;
	
	//pair<int, int> road[10001];
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end());

	bool done = true;
	int len, result = 0, cnt, rest;

	for (int i = 1; i < n; i++){

		if (len = v.at(i - 1).second - v.at(i - 1).first >= l) {
			cnt = len / l;
			if (rest = len % l == 0) {
				continue;
			}
			else {
				cnt++;
			}
		}
		else if (v.at(i).first - v.at(i - 1).second > l) {
			
		}
		

		result += cnt;

	}




}
