#include <iostream>
#include <vector>
#define ll long long
#define M 1000000007
ll n, l, r, ans, build[101], visit[101];

void dfs(ll build[], ll visit[], ll count, ll lcheck, ll visible_height, ll rcheck, bool descending) {

	if (build[0] > n - l) return;
	if (!descending && visit[n - 1]) {
		if (lcheck != l)	return;
		else				descending = true;
	}

	if (count == n) {
		if (lcheck == l && rcheck == r) {
			for (int i = 0; i < n; i++) std::cout << build[i] << " ";
			std::cout << "     :::     " << lcheck << ", " << rcheck << '\n';

			ans = (ans + 1) % M;
			return;
		}
	}

	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;

		//std::cout << "count : " << count << ", " << "build[conut] : " << build[count] << '\n';

		build[count] = i;
		visit[i] = true;


		if (!descending && build[count - 1] < build[count]) {
			lcheck++;
		}
		else if (descending && build[count - 1] > build[count]) rcheck++;

		dfs(build, visit, count + 1, lcheck, visible_height, rcheck, descending);

		if (!descending && build[count - 1] < build[count]) lcheck--;
		else if (descending && build[count - 1] > build[count]) rcheck--;
		build[count] = 0;
		visit[i] = false;
	}
}
/*
5 3 2
0 1 4 2 3      :::     3, 2
0 2 1 4 3      :::     3, 2
0 2 4 1 3      :::     3, 2
0 3 1 4 2      :::     3, 2
0 3 2 4 1      :::     3, 2
0 3 4 1 2      :::     3, 2
1 0 2 4 3      :::     3, 2
1 0 3 4 2      :::     3, 2
1 2 0 4 3      :::     3, 2
1 2 4 0 3      :::     3, 2
1 3 0 4 2      :::     3, 2
1 3 2 4 0      :::     3, 2
1 3 4 0 2      :::     3, 2
2 0 1 4 3      :::     3, 2
2 0 3 4 1      :::     3, 2
2 1 3 4 0      :::     3, 2
2 3 0 4 1      :::     3, 2
2 3 1 4 0      :::     3, 2
2 3 4 0 1      :::     3, 2

3 0 1 4 2      :::     3, 2
3 0 2 4 1      :::     3, 2
3 1 2 4 0      :::     3, 2
22
*/

int main() {
	std::cin >> n >> l >> r;

	//// TLE
	// dfs(build, visit, 0, 1, 0, 1, false);


	for (int i = 0; i <= n - l; i++) {			// start num

		for (int j = 0; j < n - 1; j++) {			// n - 1 times to add num

			for (int k = 0; k < n; k++) {
				if (visit[k]) continue;
				visit[k] = true;
				//build[i] 
			}
		}
	}

	std::cout << ans;
	return 0;
}