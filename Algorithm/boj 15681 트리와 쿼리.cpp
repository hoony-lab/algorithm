#include <iostream>
#include <vector>

#define FIO std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL);


int visited[100001], cnt[100001];
std::vector<int> tree[100001];

int query(int n) {

	cnt[n] = 1;
	visited[n] = true;

	//for (int node = 0; node < (int)tree[n].size(); ++node) {
	//	if (visited[tree[n][node]]) continue;
	//	//std::cout << "visiting : " << tree[n][node] + 1 << '\n';
	//	dist[n] += query(tree[n][node]);
	//}

	for (auto node : tree[n]) {
		if (visited[node]) continue;
		cnt[n] += query(node);
	}

	return cnt[n];
}

int main() {	FIO;

	int nodes, r, q, u, v;
	std::cin >> nodes >> r >> q;

	for (int i = 1; i < nodes; i++) {
		std::cin >> u >> v;
		--u, --v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	query(r - 1);

	while (q--) {
		std::cin >> nodes;
		std::cout << cnt[nodes - 1] << '\n';
	}

	return 0;
}