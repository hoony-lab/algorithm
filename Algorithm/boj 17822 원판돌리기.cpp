#include <iostream>
#include <queue>
#define FIO std::ios_base::sync_with_stdio(false), std::cin.tie(NULL);
#define FOR(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 51
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int n, m, t, cir[MAX][MAX], xi, di, ki, state[MAX], sum[MAX], ans;

int check_di(int dir) {
	if (di == 1)	return (dir + 1) % 4;
	else			return (dir + 3) % 4;
}

void print(int map[][MAX]) {
	for (int x = 1; x <= n; x++) {
		for (int y = 0; y < m; y++)
			std::cout << map[x][y] << " ";
		std::cout << '\n';
	}std::cout << "\n\n";
}
int main() {
	FIO;

	std::cin >> n >> m >> t;
	for (int x = 1; x <= n; x++) for (int y = 0; y < m; y++)
		std::cin >> cir[x][y], sum[x] += cir[x][y];

	while (t--) {
		std::cin >> xi >> di >> ki;

		// xi 번 원판
		int tmp_cir[MAX][MAX] = { 0, };
		for (int i = xi; i <= n; i += xi) {

			int adj = false;

			// di 방향, ki 번 반복
			if (di == 0)	state[xi] = (1 * ki) % m;
			else			state[xi] = (3 * ki) % m;

			// 인접하면서 같은 수의 원판
			for (int num = 0; num < m; ++num) {
				int tx, ty = (num + state[xi]) % m;

				// 인접한 번호 검사
				for (int a = 0; a < 4; ++a) {
					int nx = xi + dx[a];
					int ny = (ty + dy[a]) % m;

					if (nx < 1 || nx > n || cir[nx][ny] < -1e6) continue;
					if (cir[nx][ny] != cir[xi][ty]) continue;

					adj = true;
					tmp_cir[nx][ny] = tmp_cir[xi][ty] = 1e8 /*-cir[tx][ty];*/;
				}
			}

			// 인접한 같은 수 가 없으면
			if (adj) continue;

			// 평균보다 큰수 - 1, 작은수 + 1
			for (int y = 0; y < m; y++) {
				if (cir[xi][(y + state[xi]) % m] > sum[xi] / m)
					sum[xi]--, cir[xi][(y + state[xi]) % m] -= 1;
				else	sum[xi]++, cir[xi][(y + state[xi]) % m] += 1;
			}

			print(tmp_cir);

		}
		// 인접하면서 같은 수 지우기
		for (int x = 1; x <= n; x++) for (int y = 0; y < m; y++)
			cir[x][y] -= tmp_cir[x][y];
	}

	// 모든 원판의 수 더하기
	for (int x = 1; x <= n; x++) for (int y = 0; y < m; y++)
		if (cir[x][y] > -1e6) ans += cir[x][y];

	print(cir);

	std::cout << ans << '\n';
	return 0;
}