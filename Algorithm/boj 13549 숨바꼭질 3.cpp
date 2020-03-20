//#include <iostream>
//
//int ans = 987654321, visited[1000001];
//void dfs(int subin, int sister, int count) {
//	if (subin == sister) {
//		if (ans > count) ans = count;
//		return;
//	}
//	if (ans < count || subin > sister + 2 || subin <= 0 || subin > 100000) return;
//	
//	visited[subin] = 2;
//	//std::cout << "vsiting : " << subin << '\n';
//	if (visited[subin * 2] != 2)
//		dfs(subin * 2, sister, count );
//
//	if (visited[subin + 1] != 2)
//		dfs(subin + 1, sister, count + 1);
//
//	if (visited[subin - 1] != 2)
//		dfs(subin - 1, sister, count + 1);
//
//	visited[subin] = 0;
//}
//int main() {
//	int n, k;
//	std::cin >> n >> k;
//
//	dfs(n, k, 0);
//
//	std::cout << ans;
//
//	return 0;
//}


#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int visited[100001];
int main() {
	int n, k, temp, depth = 0;
	cin >> n >> k;
	//using bfs
	for (int i = 0; i < 100001; ++i) visited[i] = 987654321;
	queue<int> q;

	visited[n] = 0;
	q.push(n);

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		if (temp == k) {
			cout << visited[k];
			break;
		}

		if (temp - 1 >= 0 && visited[temp - 1] > visited[temp] + 1) {
			visited[temp - 1] = visited[temp] + 1;
			q.push(temp - 1);
		}

		if (temp + 1 <= 100000 && visited[temp + 1] > visited[temp] + 1) {
			visited[temp + 1] = visited[temp] + 1;
			q.push(temp + 1);
		}

		if (temp * 2 <= 100000 && visited[temp * 2] > visited[temp]) {
			visited[temp * 2] = visited[temp];
			q.push(temp * 2);
		}
	}

	return 0;
}