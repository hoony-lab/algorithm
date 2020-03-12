#include <iostream>
#define MIN(x,y) x < y ? x : y
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int main() {

	char map[51][51], map2[51][51];

	int n, m, min_ans = 1e9;
	std::cin >> n >> m;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			std::cin >> map[x][y], map2[x][y] = map[x][y];

	for (int i = 8; i <= n; i++) {
		for (int j = 8; j <= m; j++) {

			//std::cout << "ending : " << i << ", " << j << '\n';
			int ans = 0, ans2 = 0;
			for (int x = i - 8; x < i; x++) {
				for (int y = j - 8; y < j; y++) {

					int is_odd = (x + y) % 2;

					if (!is_odd) {
						if (map[x][y] != 'B') ans++;
						else ans2++;
					}
					else {
						if (map[x][y] != 'W') ans++;
						else ans2++;
					}
				}
			}
			//std::cout << ans << ", " << ans2 << '\n';
			ans = MIN(ans, ans2);
			min_ans = MIN(min_ans, ans);
		}
	}
	std::cout << min_ans;

}
