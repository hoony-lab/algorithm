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
int n, m, r, c, d;
int map[MAX][MAX];

bool check(int x, int y) {
	return !(/*x <= 0 || y <= 0 || x >= n - 1 || y >= m - 1 ||*/ map[x][y] == 1);
}

p turn(int x, int y, int way, int turn){
	return {x + dx[(4 + way - turn) % 4] , y + dy[(4 + way - turn) % 4] };
}

void play() {
	int tx = r, ty = c, way = d;
	while (1) {
		bool done = false;

		F(a, 4) {
			//int nx = tx + dx[a], ny = ty + dy[a];
			p npos = turn(tx, ty, d, LEFT + a);

			if (map[npos.x][npos.y]) continue;
			
			map[npos.x][npos.y] = -1;

			d = (4 + d - (LEFT + a));
			
			
			break;

		}
		if (done) return;
	}
}
int main() {
	std::cin >> n >> m >> r >> c >> d;

	play();

	return 0;
}