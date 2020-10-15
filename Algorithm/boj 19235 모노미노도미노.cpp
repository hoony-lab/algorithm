#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define FNM(i, n, m) for(int i = m ; i < n ; ++i)
#define FRNM(i, n, m) for(int i = n ; i >= m ; --i)
#define MAX 10
enum WAY{ UP, RIGHT, DOWN, LEFT };

struct BLOCK { int t, x1, y1, x2, y2; }; // 2개
int time, tt, xx, yy, ans, ans_cnt;
int map[MAX][MAX];
BLOCK block;	

// t = 1: 크기가 1×1인 블록을(x, y)에 놓은 경우
// t = 2 : 크기가 1×2인 블록을(x, y), (x, y + 1)에 놓은 경우
// t = 3 : 크기가 2×1인 블록을(x, y), (x + 1, y)에 놓은 경우
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void print_block(BLOCK block) {
	cout << " # " << block.t << ", " << block.x1 << ", " << block.y1 << ", " << block.x2 << ", " << block.y2 << '\n';
}

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

void go_down_and_right() {
	BLOCK b = block;
	
	if (b.t == 1) {
		// down
		int nx1 = b.x1, ny1 = b.y1;
		while (check(nx1 + 1, ny1) && map[nx1 + 1][ny1] == 0) 
			nx1++;

		map[nx1][ny1] = 1;

		// right
		nx1 = b.x1, ny1 = b.y1;
		while (check(nx1, ny1 + 1) && map[nx1][ny1 + 1] == 0)
			ny1++;

		map[nx1][ny1] = 1;
	}
	else if(b.t == 2) {
		// down
		int nx1 = b.x1, ny1 = b.y1, nx2 = b.x2, ny2 = b.y2;
		while (check(nx1 + 1, ny1) && map[nx1 + 1][ny1] == 0
			&& check(nx2 + 1, ny2) && map[nx2 + 1][ny2] == 0)
			nx1++, nx2++;

		map[nx1][ny1] = 1, map[nx2][ny2] = 1;

		// right
		nx1 = b.x1, ny1 = b.y1, nx2 = b.x2, ny2 = b.y2;
		while (check(nx2, ny2 + 1) && map[nx2][ny2 + 1] == 0)
			ny1++, ny2++;

		map[nx1][ny1] = 1, map[nx2][ny2] = 1;
	}
	else if (b.t == 3) {
		// down
		int nx1 = b.x1, ny1 = b.y1, nx2 = b.x2, ny2 = b.y2;
		while (check(nx2 + 1, ny2) && map[nx2 + 1][ny2] == 0)
			nx1++, nx2++;

		map[nx1][ny1] = 1, map[nx2][ny2] = 1;

		// right
		nx1 = b.x1, ny1 = b.y1, nx2 = b.x2, ny2 = b.y2;
		while (check(nx1, ny1 + 1) && map[nx1][ny1 + 1] == 0
			&& check(nx2, ny2 + 1) && map[nx2][ny2 + 1] == 0)
			ny1++, ny2++;

		map[nx1][ny1] = 1, map[nx2][ny2] = 1;
	}
	//print_block(b);
	//print();
}

int check_down_special_section() {
	int cnt = 0;
	FNM(x, 6, 4) F(y, 4) if (map[x][y] != 0) {
		cnt++; break;
	}
	return cnt;
}
int check_right_special_section() {
	int cnt = 0;
	FNM(y, 6, 4) F(x, 4) if (map[x][y] != 0) {
		cnt++; break;
	}
	return cnt;
}

void push_down_right_line() {
	// down
	int down_cnt = check_down_special_section();
	if (down_cnt) {
		FRNM(x, MAX - 1 - down_cnt, 0) F(y, 4) {
			map[x + down_cnt][y] = map[x][y];
		}
	}
	
	// right
	int right_cnt = check_right_special_section();
	if (right_cnt) {
		FRNM(y, MAX - 1 - right_cnt, 0) F(x, 4) {
			map[x][y + right_cnt] = map[x][y];
		}
	}
}

int find_n_erase_down_one_line() {
			print();
	bool find_line = false;
	FRNM(x, MAX - 1, 2) {
		int cnt = 0;
		F(y, 4) if (map[x][y] == 1) cnt++;

		if (cnt == 4) {
			F(y, 4) map[x][y] = 0;
			ans++;
			find_line = true;

			cout << "FIND LINE x : " << x << '\n';
		}
	}
	return find_line;
}
int find_n_erase_right_one_line() {
	bool find_line = false;
	FRNM(y, MAX - 1, 2) {
		int cnt = 0;
		F(x, 4) if (map[x][y] == 1) cnt++;

		if (cnt == 4) {
			F(x, 4) map[x][y] = 0;
			ans++;
			find_line = true;

			cout << "FIND LINE y : " << y << '\n';
		}
	}
	return find_line;
}

void erase_line() {
	// find all down one line
	while(find_n_erase_down_one_line()) {
		print();
		cout << "! DROP DOWN !\n";
		// drop blocks
		F(y, 4) {
			int x = MAX;
			while (check(x - 1, y)) {			// 아래서 올라가다가
				x--;
				if (map[x][y] == 0) {			// 빈칸을 찾으면
					int nx = x;
					while (check(nx - 1, y)) {	// 있는 칸 찾기
						nx--;
						if (map[nx][y] != 0) {	// 있는칸 찾으면
							map[x][y] = 1, map[nx][y] = 0, x++; break;
						}
					}
				}
			}
		}
	}

	// find all right one line
	while(find_n_erase_right_one_line()) {

		// drop blocks
		F(x, 4) {
			int y = MAX;
			while (check(x, y - 1)) {			// 아래서 올라가다가
				y--;
				if (map[x][y] == 0) {			// 빈칸을 찾으면
					int ny = y;
					while (check(x, ny - 1)) {	// 있는 칸 찾기
						ny--;
						if (map[x][ny] != 0) {	// 있는칸 찾으면
							map[x][y] = 1, map[x][ny] = 0, y++; break;
						}
					}
				}
			}
		}
	}
}

int main() {
	// init();
	cin >> time;
	F(i, time) {
		memset(&block, 0, sizeof(block));

		cin >> tt >> xx >> yy;
		block = { tt, xx, yy };

		if (tt == 2)		block.x2 = xx, block.y2 = yy + 1;
		else if (tt == 3)	block.x2 = xx + 1, block.y2 = yy;

		go_down_and_right(); 
		push_down_right_line();
		erase_line();

		print();
	}

	F(x, MAX) F(y, MAX) if (map[x][y]) ans_cnt++;

	cout << ans << '\n' << ans_cnt;

	return 0;
}
/*

6
1 0 0
1 0 2
2 0 0
3 0 2
2 0 1
3 0 3

>> 블록 단위로 떨어짐
2
11

*/