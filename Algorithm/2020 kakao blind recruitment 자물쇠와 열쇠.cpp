// https://programmers.co.kr/learn/courses/30/lessons/60059
#include <iostream>
#include <string>
#include <vector>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define FS(i, n, m) for(int i = m ; i < n ; ++i)
#define FR(i, n) for(int i = n - 1; i >= 0 ; --i)
using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;
struct pos {
	int x, y;
};
int  key_size, lock_size;
vector<pos> possible_key, empty_lock;

void print(vvi v) {
	F(x, v.size()) {
		F(y, v.size()) {
			cout << v[x][y] << " ";
		}cout << '\n';
	}cout << "\n\n";
}

bool check(int x, int y, int size) {
	return !(x < 0 || y < 0 || x >= size || y >= size);
}

bool check_lock(vvi lock, int dx, int dy) {
	vvi vv = lock;

	for (auto p : possible_key) {
		if (!check(p.x + dx, p.y + dy, n)) continue;

		//// LOCK is 1 on key pos
		if (lock[p.x + dx][p.y + dy]) return false;

		vv[p.x + dx][p.y + dy] += 1;
	}

	for (auto p : empty_lock)
		if (!vv[p.x][p.y]) return false;

	return true;
}

vvi rotate(vvi key) {
	/*
	rotate 90^ to right
	1 2 3   7 4 1
	4 5 6   8 5 2
	7 8 9   9 6 3
	*/

	vvi vv;
	F(y, key_size) {
		vi v;
		FR(x, key_size) v.push_back(key[x][y]);
		vv.push_back(v);
	}
	return vv;
}

bool solution(vvi key, vvi lock) {
	/*
	0. find '0' in lock
	do{
	1.1 find '1' in key
	1.2 check all possible KEY cases starting from external position
		which is overlapping with the LOCK
	1.3 rotate key
	} while(done);
	*/

	key_size = key.size();
	lock_size = lock.size();

	F(x, lock_size) F(y, lock_size)
		if (!lock[x][y]) empty_lock.push_back({ x, y });

	//print(lock);

	//// four ways rotation
	F(a, 4) {
		//print(key);

		F(x, key_size) F(y, key_size)
			if (key[x][y]) possible_key.push_back({ x, y });

		//// search starting point from external position
		FS(x, lock_size, -key_size) FS(y, lock_size, -key_size) {
			if (check_lock(lock, x, y))
				return true;
		}
		key = rotate(key);
		possible_key.clear();
	}
	return false;
}

int main() {
	vvi key = { {0, 0, 0}, {1, 0, 0}, {0, 1, 1} };
	vvi key2 = { {1, 0}, {0, 1} };
	vvi lock = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };

	solution(key, lock) ? cout << "TRUE" : cout << "FALSE";

	return 0;
}