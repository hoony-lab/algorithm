#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
using namespace std;

int n, min_gap = 1e9, map[21][21];
vector<int> v;

void dfs() {
	vector<int> start, link;
	int start_sum = 0, link_sum = 0;
	F(i, n) v[i] ? start.push_back(i) : link.push_back(i);

	//cout << "\nSTART\n";
	//F(i, n / 2) cout << start[i] << ", "; cout << '\n';
	//F(i, n / 2) cout << link[i] << ", "; cout << '\n';

	for (int i = 0; i < n / 2 - 1; ++i) {
		for (int j = i + 1; j < n / 2; ++j) {
			start_sum += map[start[i]][start[j]] + map[start[j]][start[i]];
			link_sum += map[link[i]][link[j]] + map[link[j]][link[i]];
		}
	}
	min_gap = min(min_gap, abs(start_sum - link_sum));
}


int main() {

	cin >> n;
	F(x, n) F(y, n) cin >> map[x][y];

	vector<int> ppl(n, 0);

	F(i, n / 2) ppl[n / 2 + i] = 1;

	do {
		v = ppl;
		dfs();
	} while (next_permutation(ppl.begin(), ppl.end()));

	cout << min_gap;
	return 0;

}