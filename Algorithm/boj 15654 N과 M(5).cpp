#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v, ans;
int visit[10];
int n, m, t;
void dfs(int cnt) {
	if (cnt == m) {
		for (int num : ans) cout << num << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (visit[i]) continue;
		visit[i] = true;
		ans.push_back(v[i]);
		dfs(cnt + 1);
		ans.pop_back();
		visit[i] = false;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) 
		cin >> t, v.push_back(t);

	sort(v.begin(), v.end());

	dfs(0);
	return 0;
}