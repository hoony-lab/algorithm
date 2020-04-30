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

int n, answer;
vector<vector<int>> map;
vector<pair<int, int>> block[BLOCKMAX];
set<int> block_num;

void print_map() {
	F(x, n) {
		F(y, n) {
			cout << map[x][y] << " ";
		}cout << "\n";
	}cout << "\n\n";
}

void print_block(){
	for (int num : block_num) {
		cout << num << "\t< \t";
		for (auto pos : block[num]) {
			cout << pos.first << ", " << pos.second << "  ||  ";
		}
		cout << '\n';
	}cout << "\n\n";
}


bool check(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	return true;
}

void erase_block(int num) {
	for (auto pos : block[num]) {
		int x = pos.first, y = pos.second;
		map[x][y] = 0;
		block_num.erase(num);
	}
}

bool is_block_opened(int num) {
	for (auto pos : block[num]) {
		int nx = pos.first, ny = pos.second;

		while (check(--nx, ny)) {
			if (map[nx][ny] == 0 ||
				map[nx][ny] == map[pos.first][pos.second]) continue;

			return false;
		}
	}
	return true;
}

bool check_shape(int x, int y) {
	int tx = x, ty = y;

	F(a, 5) {
		bool fail = false;
		F(b, 4) {
			int nx = tx + blockx[a][b];
			int ny = ty + blocky[a][b];

			if (!check(nx, ny) || map[x][y] != map[nx][ny])
				fail = true;
		}
		if (!fail) return true;
	}
	return false;
}

void solve() {

	for (int num : block_num) {
		if (!is_block_opened(num)) continue;
		erase_block(num);

		//print_map();

		answer++; 
		solve();
		return;
	}
}


int solution(vector<vector<int>> board) {
	
	//map.assign(board.begin(), board.end());
	map = board;
	n = board.size();

	FR(x, n) FR(y, n) {
		if (!map[x][y]) continue;

		if (check_shape(x, y)) 
			block_num.insert(map[x][y]);

		block[map[x][y]].push_back(make_pair(x, y));
	}

	//print_block();

	solve();

	return answer;
}






int main() {

	vector<vector<int>> board = {
		{0, 0, 0, 0, 0, 0, 11, 11, 11, 0},
		{0, 0, 0, 0, 6, 0, 0, 0, 11, 0},
		{0, 0, 10, 0, 6, 6, 6, 0, 0, 0},
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