#include <iostream>
#include <vector>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 51

// U R D L
// wall 1, empty 0
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
struct p { int x, y; };
int n, m, r, c, d;
int map[MAX][MAX];
bool check(int x, int y) {
	return !(/*x <= 0 || y <= 0 || x >= n - 1 || y >= m - 1 ||*/ map[x][y] == 1);
}

p turn(int x, int y, int way) {
	return { (x + 3 + dx[way]) % 4, (y + 3 + dy[way]) % 4 };
}

int main() {
	std::cin >> n >> m >> r >> c >> d;

	int tx = r, ty = c;
	F(a, 4) {
		int nx = tx + dx[a], ny = ty + dy[a];
		
	}

	return 0;
}