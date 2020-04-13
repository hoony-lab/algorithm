#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define FOR(i, n) for (int i = 0 ; i < n ; ++i)

// R L U D
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0};

struct pos {
	std::vector<std::pair<int, int>> v;
}

int main() {
	int n, k, map[13][13];
	std::cin >> n >> k;
	
	FOR(x, n) FOR(y, n) std::cin >> map[x][y];

	FOR(i, k) {
		std::cin >> 
	}

	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(0, 0));
	
	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		FOR(a, 4) {
			int nx = tx + dx[a];
			int ny = ty + dy[a];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			q.push({ nx,ny });
			
			if (map[nx][ny] == 0) {

			}
			else if (map[nx][ny] == 1) {

			}
			else if (map[nx][ny] == 2) {

			}
		}
	}
	return 0;
}{