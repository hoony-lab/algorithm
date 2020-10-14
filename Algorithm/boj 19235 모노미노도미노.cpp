#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define FNM(i, n, m) for(int i = m ; i < n ; ++i)
#define MAX 10
struct BLOCK { int t, x, y; };
int time, tt, xx, yy, ans[2];
int map[MAX][MAX];
BLOCK block[2];

// t = 1: 크기가 1×1인 블록을(x, y)에 놓은 경우
// t = 2 : 크기가 1×2인 블록을(x, y), (x, y + 1)에 놓은 경우
// t = 3 : 크기가 2×1인 블록을(x, y), (x + 1, y)에 놓은 경우
//int dx[] = { 0, 0, 1 };
//int dy[] = { 0, 1, 0 };

void print() {
	F(x, MAX){
		F(y, MAX) {
			cout << map[x][y] << ' ';
		} cout << '\n';
	} cout << "\n\n";
}

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= MAX || y >= MAX);
}

void init() {
}

void erase_line() {
	// down
	F(x, MAX) F(y, MAX / 2) {
		if()
	}

	// right
	F(x, MAX / 2) F(y, MAX) {
		if ()
	}
}
void drop_blocks() {
	F()
}

void go_down() {
	
}

void go_right() {

}



int main() {
	// init();
	cin >> time;
	F(i, time) {
		memset(block, 0, sizeof(block));
		cin >> tt >> xx >> yy;
		block[0] = { tt, xx, yy };

		if (tt == 1)		block[1] = { tt, xx, yy - 1 };
		else if (tt == 2)	block[1] = { tt, xx - 1, yy };
		








	}
	cout << ans[0] << '\n' << ans[1];
	return 0;
}