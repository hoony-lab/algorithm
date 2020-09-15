#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001
#define SUCCESS cout << "King-God-Emperor"
#define FAIL cout << "Lier!"

// 입력의 첫 줄에는 건물 종류의 개수 N
// 건물 사이 관계의 개수 M
// 영우의 게임 정보의 개수 K
int n, m, k, ans;
int construct[MAX], condition[MAX];
vector<int> vec[MAX], vec2[MAX];

// 1 a(영우가 a번 건물을 1개 건설함)
// 2 a(영우의 a번 건물이 1개 파괴됨)

int find_condition(int v) {
	for (int building : vec[v])
		if (!construct[building]) return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m >> k;

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		vec[u].push_back(v);	// >>
		vec2[v].push_back(u);	// <<
	}

	for (int i = 0; i < k; i++) {
		cin >> u >> v;

		// construct
		if (u == 1) {
			// 건설할 수 없는 건물을 건설하거나
			//if (!find_condition(v)) {
			if (condition[v] != vec2[v].size()) {
				FAIL;
				return 0;
			}
			else {
				construct[v]++;
				for (int building : vec[v])
					condition[building]++;
			}
		}
		// destroy
		else if (u == 2) {
			// 건설한적 없는 건물이 파괴되었다면
			if (!construct[v]) {
				FAIL;
				return 0;
			}
			else {
				construct[v]--;
				for (int building : vec[v])
					condition[building]--;
			}
		}

	}
	SUCCESS;
	return 0;
}