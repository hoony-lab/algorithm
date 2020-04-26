//https://programmers.co.kr/learn/courses/30/lessons/42894
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define FR(i, n) for(int i = n - 1 ; i >= 0; --i)
#define BLOCKMAX 201
using namespace std;

// ¤¤ J L ¤Ò ¤Ç
// start from the bottom which has no upper block
// right to left
//int blockx[5][3] = {
//	{0, 0, -1},
//	{0,-1, -2},
//	{0,-1, -2},
//	{0, 0, -1},
//	{0, 0, -1} };
//int blocky[5][3] = {
//	{-1, -2, -2 },
//	{1, 1, 1},
//	{-1, -1, -1},
//	{-1, 1, 1},
//	{-1, -2, -1} };

int blockx[5][4] = {
	{0, 0, 0, -1},
	{0, 0,-1, -2},
	{0, 0,-1, -2},
	{0, 0, 0, -1},
	{0, 0, 0, -1} };
int blocky[5][4] = {
	{0, -1, -2, -2 },
	{0, -1, 0, 0},
	{0, -1, -1, -1},
	{0, -1, -2, 0},
	{0, -1, -2, -1} };

int n, opened_block[BLOCKMAX], answer;
vector<vector<int>> map;
vector<pair<int, int>> block[BLOCKMAX];
set<int> block_num;

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

bool is_opened(int x, int y) {
	int nx = x, ny = y;

	// move up
	while (check(--nx, ny)) {

		// if map is 0 or same as starting point, move up
		if (map[nx][ny] == 0 || map[nx][ny] == map[x][y]) continue;

		opened_block[map[x][y]] = false;
		return false;
	}
	return true;
}

bool is_opened2(int num) {
	int x = block[num].front().first;
	int y = block[num].front().second;

	for (auto a : block[num]) {
		int nx = a.first, ny = a.second;

		// move up
		while (check(--nx, ny)) {

			// if map is 0 or same as starting point, move up
			if (map[nx][ny] == 0 || map[nx][ny] == map[x][y]) continue;

			opened_block[map[x][y]] = false;
			return false;
		}
		return true;
	}
}

bool check_block_shape(int x, int y) {
	//cout << "check shape : " << x << " ," << y << '\n';
	// check 5 possible shape
	F(a, 5) {
		bool fail = false;

		F(b, 4) {

			// if map is not same as starting point or closed
			int nx = x + blockx[a][b], ny = y + blocky[a][b];
			if (!check(nx, ny) || map[nx][ny] != map[x][y] || !is_opened(nx, ny))
				fail = true;
		}

		if (!fail && opened_block[map[x][y]]) {

			// erase number on the erasable block
			F(b, 4) map[x + blockx[a][b]][y + blocky[a][b]] = 0;

			// debugging
			//cout << "Done at " << x << ", " << y << " : " << "shape : " << a << "\n";
			//print();

			return true;
		}
	}
	return false;
}

bool check_block_shape2(int num) {
	int x = block[num].front().first;
	int y = block[num].front().second;

	F(a, 5) {
		bool fail = false;

		F(b, 4) {
			int nx = x + blockx[a][b];
			int ny = y + blocky[a][b];

			if (nx != block[num][b].first || ny != block[num][b].second || !is_opened(nx, ny))
				fail = true;
		}

		if (!fail) {

			// erase number on the erasable block
			F(b, 4) map[x + blockx[a][b]][y + blocky[a][b]] = 0;
			block_num.erase(num);

			// debugging
			//cout << "Done at " << x << ", " << y << " : " << "shape : " << a << "\n";
			//print();

			return true;
		}
	}
	return false;
}

bool possible_shape(int x, int y) {
	F(a, 5) {
		bool fail = false;
		F(b, 4) {
			int nx = x + blockx[a][b];
			int ny = y + blocky[a][b];

			if (!check(nx, ny) || map[x][y] != map[nx][ny])
				fail = true;
		}
		if (!fail) return true;
	}
	return false;
}

void solve() {
	memset(opened_block, true, sizeof(opened_block));

	//FR(x, n) FR(y, n) {
	for (int num : block_num) {
		//if (!check_block_shape(x, y)) continue;
		//if (!check_block_shape2(num)) continue;

		if (!is_opened2(num)) continue;

		answer++;
		solve();

		return;
	}

}

int solution(vector<vector<int>> board) {
	map.clear();		map = board;
	n = board.size();

	FR(x, n) FR(y, n) {
		if (!map[x][y]) continue;
		if (possible_shape(x, y))
			block_num.insert(map[x][y]);

		block[map[x][y]].push_back(make_pair(x, y));

	}
	std::cout << "block_num.size() " << block_num.size() << '\n';
	for (int num : block_num) {
		cout << block[num].size() << " < ";
		cout << block[num].front().first << ", " << block[num].front().second << '\n';
	}
	solve();

	return answer;
}






int main() {

	vector<vector<int>> board = {
		{0, 0, 0, 0, 0, 0, 11, 0, 0, 0},
		{0, 0, 0, 0, 6, 11, 11, 11, 0, 0},
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