#include <iostream>
#include <vector>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 51
#define LEFT 1
#define BACK 2

// U R D L
// wall 1, empty 0
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
struct p { int x, y; };
int n, m, r, c, d, ans;
int map[MAX][MAX];

void print() {
	F(x, n) {
		F(y, m) {
			std::cout << map[x][y];
		}std::cout << '\n';
	}std::cout << "\n\n";
}

bool check(int x, int y) {
	return !(/*x <= 0 || y <= 0 || x >= n - 1 || y >= m - 1 ||*/ map[x][y] == 1);
}

p turn(int x, int y, int way, int turn) {
	return { x + dx[(4 + way - turn) % 4] , y + dy[(4 + way - turn) % 4] };
}

void play() {
	// int tx = r, ty = c, way = d;
	while (1) {
		bool done = false;
		
		if(map[r][c] != 2) ans++;
		// 현재 방문 지점 청소
		map[r][c] = 2;

		F(a, 4) {
			//int nx = tx + dx[a], ny = ty + dy[a];
			p npos = turn(r, c, d, LEFT + a);

			// 가려는 곳이 벽이거나 청소되었으면 다음 방향
			if (map[npos.x][npos.y] == 1 || map[npos.x][npos.y] == 2) continue;

			// 가려는 곳이 청소 안되었으면 전진
			if (map[npos.x][npos.y] == 0) {
				r = npos.x, c = npos.y;
				d = (4 + d - (LEFT + a)) % 4;
				done = true;
				break;
			}
		}
		std::cout << "TIME : " << ans << '\n';
		print();

		// 청소할 장소를 찾으면 패스
		if (done) continue;

		// 뒤가 벽이면
		// 뒤가 벽이 아니면
		p bpos = turn(r, c, d, BACK);
		if (map[bpos.x][bpos.y] == 1 || map[bpos.x][bpos.y] == 2)
			return;
		else
			r = bpos.x, c = bpos.y, d = (4 + d - (BACK)) % 4;
	}
}
int main() {
	std::cin >> n >> m >> r >> c >> d;
	F(x, n) F(y, m) std::cin >> map[x][y];

	play();

	std::cout << ans;
	return 0;
}