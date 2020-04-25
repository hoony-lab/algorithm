#include <iostream>
#include <vector>
#include <cstring>

#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define FR(i, n) for(int i = n - 1 ; i >= 0; --i)
#define BLOCKMAX 201
using namespace std;

// ¤¤ J L ¤Ò ¤Ç
// start from the bottom which has no upper block
int blockx[5][3] = {
	{0, 0, -1},
	{0,-1, -2},
	{0,-1, -2},
	{0, 0, -1},
	{0, 0, -1} };
int blocky[5][3] = {
	{-1, -2, -2 },
	{1, 1, 1},
	{-1, -1, -1},
	{-1, 1, 1},
	{-1, -2, -1} };

int n, block[BLOCKMAX], answer;
vector<vector<int>> map;

void print() {
	F(x, n) {
		F(y, n) {
			cout << map[x][y] << " ";
		}cout << "\n";
	}cout << "\n\n";
}

bool check(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	return true;
}

bool is_closed(int x, int y) {
	int nx = x, ny = y;

	while (check(--nx, ny)) {
		if (map[nx][ny] == 0 || map[nx][ny] == map[x][y]) continue;
		if (block[map[x][y]]) continue;
		block[map[x][y]] = true;
		return true;
	}
	return false;
}

bool check_block_shape(int x, int y) {

	F(a, 5) {
		bool fail = false;
		F(b, 3) {
			int nx = x + blockx[a][b], ny = y + blocky[a][b];
			if (!check(nx, ny) || map[nx][ny] != map[x][y])
				fail = true;
		}

		if (!fail && !block[map[x][y]]) {
			// erase number on the erasable block
			map[x][y] = 0;
			F(b, 3) map[x + blockx[a][b]][y + blocky[a][b]] = 0;

			// debugging
			cout << "Done at " << x << ", " << y << " : " << "shape : " << a <<"\n";
			print();

			return true;
		}
	}
	return false;
}


void solve() {
	memset(block, 0, sizeof(block));

	FR(x, n) FR(y, n) {
		if (!map[x][y]) continue;
		if (is_closed(x, y)) continue;
		if (!check_block_shape(x, y)) continue;

		answer++;
		solve();
	}
}

int solution(vector<vector<int>> board) {
	map.clear();		map = board;
	n = board.size();

	solve();

	return answer;
}






int main() {

	vector<vector<int>> board = {
		{0, 0, 11, 11, 11, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 6, 0, 0, 0, 0, 0},
		{0, 0, 10, 6, 6, 6, 0, 0, 0, 0},
		{0, 10, 10, 10, 0, 0, 0, 0, 0, 0},
		{7, 0, 0, 9, 0, 0, 4, 0, 0, 8},
		{7, 7, 7, 9, 0, 4, 4, 0, 8, 8},
		{0, 0, 9, 9, 3, 0, 4, 0, 0, 8},
		{0, 0, 0, 2, 3, 0, 0, 0, 5, 5},
		{1, 2, 2, 2, 3, 3, 0, 0, 0, 5},
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 5}
	};
	cout << solution(board);	// 2
	
	return 0;
}