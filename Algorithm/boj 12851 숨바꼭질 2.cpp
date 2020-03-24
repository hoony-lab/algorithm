#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int visited[100001];
int main() {
	int n, k, temp, ans = 0;
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
			//cout << visited[k];
			ans++;
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
			visited[temp * 2] = visited[temp] + 1;
			q.push(temp * 2);
		}

		if (ans > 2) break;
	}
	std::cout << visited[k] << "\n" << ans;

	return 0;
}
