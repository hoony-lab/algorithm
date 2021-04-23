#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int n, num[1'000'001], tnum[1'000'001];
map<int, int> m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		tnum[i] = num[i];
		m[num[i]] = -1;
	}
	sort(tnum, tnum + n);
	// -10 -9 2 4 4

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (m[tnum[i]] == -1) m[tnum[i]] = cnt++;
	}

	for (int i = 0; i < n; i++) {
		cout << m[num[i]] << ' ';
	}
	return 0;
}