#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#define FOR(i, n) for(int i = 0 ; i < n ; ++i)
#define DOT '.'
#define WALL '*'
#define PAPER '$'

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

std::vector<std::pair<int, int>> enter;

std::set<std::pair<int, int>> door;
std::set<char> key;


std::string keys;
char map[101][101];
int h, w, visit[101][101], ans;



void open_door_with_key(int nx, int ny) {
	for (char k : key) {
		if (k == map[nx][ny]) {
			door.erase({ nx, ny });
			map[nx][ny] = DOT;
		}
	}
}

bool is_key(char ch) {
	if ('a' <= ch && ch <= 'z')
		return true;
	else return false;
}

bool is_door(char ch) {
	if ('A' <= ch && ch <= 'Z')
		return true;
	else return false;
}

bool is_paper(char ch) {
	if (ch == PAPER)
		return true;
	else return false;
}

void bfs(int i) {

	int startx = enter[i].first;
	int starty = enter[i].second;

	std::queue<std::pair<int, int>> q;
	q.push({ startx, starty });

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		FOR(a, 4) {
			int nx = tx + dx[a];
			int ny = ty + dy[a];

			if (nx < 0 || ny < 0 || nx >= h || ny >= w || map[nx][ny] == WALL) continue;

			if (is_key(map[nx][ny])) {
				key.insert(map[nx][ny]);
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}

			if (is_door(map[nx][ny])) {
				open_door_with_key(nx, ny);
				enter.push_back({ nx, ny });
			}

			if (is_paper(map[nx][ny])) {
				ans++;
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

void init() {

	std::cin >> h >> w;
	FOR(x, h) FOR(y, w) {
		std::cin >> map[x][y];

		if (is_door(map[x][y]))
			door[map[x][y]] = { x, y };

		if (map[x][y] != WALL && (x == 0 || y == 0 || x == h - 1 || y == w - 1))
			enter.push_back({ x, y });
	}

	std::cin >> keys;
	FOR(i, keys.size())
		key.insert(keys[i]);
}

void solve() {
	int ans = 0;

	init();

	while (true) {
		int entersize = enter.size();
		FOR(i, entersize) {

			bfs(i);

		}
	}
	std::cout << ans;
}

int main() {

	int t;
	std::cin >> t;

	while (t--) 
		solve();
	
	return 0;
}