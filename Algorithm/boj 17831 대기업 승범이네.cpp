#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int n, visited[200001], used[200001], ans;
vector<vector<int>> v(n);
vector<int> state;

void dfs(int senior, int start, int end) {

	if (v[senior].size() == 0) {
		ans = max(ans, 100);
		return;
	}

	for (int junior : v[senior]) {
		if (visited[junior]) continue;

		visited[junior] = true;
		if (used[senior]) {

			dfs();


		}
		else {
			dfs();
		}
		visited[junior] = false;
	}

}
int main() {
	cin >> n;

	for (int junior = 1, senior; junior < n; ++junior) {
		cin >> senior;
		v[senior - 1].push_back(junior);
	}
	for (int i = 0, st; i < n; ++i) {
		cin >> st;
		state.push_back(st);
	}

	used[0] = true;
	dfs(0, 0, 0);
	memset(used, 0, sizeof(used));

	dfs(0, 0, 0);
	return 0;
}