#include <iostream>
#include <vector>
using namespace std;
int visit[101], ans;
vector<int> vec[101];
void virus(int i) {
	int cnt = 1;
	visit[1] = true;
	for (int num : vec[i]) {
		if (visit[num]) continue;
		visit[num] = true;
		virus(num);
		ans++;
	}
}
int main() {
	int n, cnt, u, v; cin >> n >> cnt;
	for (int i = 0; i < cnt; ++i) {
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	virus(1);
	cout << ans;
	return 0;
}