#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#define FOR(i, n) for(int i = 1 ; i <= n; ++i)
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

int check_way(char way) {
	if (way == 'E') return 0;
	else if (way == 'S') return 1;
	else if (way == 'W') return 2;
	else if (way == 'N') return 3;
	else if (way == 'L') return -1;
	else if (way == 'R') return -2;
	else if (way == 'F') return -3;
}

bool check_boundary(int x, int y, int a, int b) {
	if (x <= 0 || y <= 0 || x > a || y > b) return false;
	else return true;
}

int main() {
	std::string ans[3] = { "Robot ", " crashes into the wall", " crashes into robot " };
	char way;
	int a, b, n, m, posx, posy, num, count;
	std::vector<std::tuple<int, int, int>> v;

	std::cin >> a >> b >> n >> m;

	// init robot pos
	FOR(i, n) {
		std::cin >> posx >> posy >> way;
		v.push_back({ posx, posy, check_way(way) });
	}

	// order robot
	FOR(i, m) {
		std::cin >> num >> way >> count;
		int tx = std::get<0>(v[num - 1]);
		int ty = std::get<1>(v[num - 1]);
		int tway = std::get<2>(v[num - 1]);
		
		int nx = tx, ny = ty, nway = tway;
		FOR(time, count) {
			if (check_way(way) == -3) {				// F
				nx += dx[nway];
				ny += dy[nway];

				// wall_crash
				if (!check_boundary(nx, ny, a, b)) {
					//std::cout << nx << ", " << ny << ", " << a << ", " << b << '\n';
					std::cout << ans[0] << num << ans[1];
					return 0;
				}
				// robot_crash
				FOR(r, n) {
					if (num == r) continue;
					if (nx == std::get<0>(v[r - 1]) && ny == std::get<1>(v[r - 1])) {
						std::cout << ans[0] << num << ans[2] << r;
						return 0;
					}
				}
			}
			else if (check_way(way) == -1) {		// L
				nway = (nway + 3) % 4;
			}
			else if (check_way(way) == -2) {		// R
				nway = (nway + 1) % 4;
			}

		}
		v[num - 1] = { nx, ny, nway };
	}

	std::cout << "OK";

	return 0;
}

/*
5 4
2 2
1 1 E
5 4 W
1 F 7
2 F 7

5 4
2 2
1 1 E
1 4 W
1 F 7
2 F 7

*/