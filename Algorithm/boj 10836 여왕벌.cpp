#include <iostream>
#include <cstring>
#define FOR(i, n) for(int i = 0 ; i < n ; ++i)

int dx[] = { -1, 0, -1, 0, 1 };
int dy[] = { -1, -1, 0, 1, 0 };

int m, n, map[701][701], temp;

void print() {
	FOR(x, m) { FOR(y, m) { std::cout << map[x][y] << " "; } std::cout << '\n'; }
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);	std::cout.tie(NULL);

	std::cin >> m >> n;

	FOR(x, m) FOR(y, m) map[x][y] = 1;

	FOR(day, n) {
		int tx = m - 1, ty = 0;

		FOR(a, 3) {
			std::cin >> temp;

			FOR(b, temp) {
				map[tx][ty] += a;

				if (tx != 0) tx--;
				else ty++;
			}
		}
	}

	//for (int x = 1; x < m; ++x) {
	//	for (int y = 1; y < m; ++y) {

	//		//int max_growth = 0;
	//		//FOR(a, 3) {
	//		//	int nx = x + dx[a];
	//		//	int ny = y + dy[a];

	//		//	max_growth = max_growth > map[nx][ny] ?
	//		//		max_growth : map[nx][ny];

	//		//	if (a == 2)
	//		//		map[x][y] = max_growth;
	//		//}

	//		map[x][y] = map[x - 1][y];
	//	}
	//}

	//print();

	FOR(x, m) {
		FOR(y, m) {
			if (x == 0 || y == 0)
				std::cout << map[x][y] << ' ';
			else
				std::cout << map[0][y] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}