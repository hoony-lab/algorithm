#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int ans;
vector<string> v;

int n, k, check[26];
int max_cnt() {

	return 1;
}
void dfs(int idx, int cnt) {
	if (k < 5) return;

	if (cnt == k - 5) {
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int tmp_cnt = 0;

			for (int j = 0; j < (int)v[i].size(); ++j) {
				if (check[v[i][j] - 'a']) tmp_cnt++;
				else break;
			}

			if (tmp_cnt == v[i].size())
				sum++;
		}

		ans = max(ans, sum);
		return;
	}

	for (int i = idx; i < 26; ++i) {
		if (check[i]) continue;
		check[i]++;
		dfs(i, cnt + 1);
		check[i]--;
	}
}
int main() {
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	// string prefix = "anta", suffix = "tica";
	// a n t i c
	check[0]++;
	check[2]++;
	check[8]++;
	check[13]++;
	check[19]++;
	
	dfs(0, 0);

	cout << ans;
	return 0;
}