//20200521 1419
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using vii = vector<pair<int, int>>;
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 101
// R U L D
int dy[] = { 0,-1,0,1 }, dx[] = { 1,0,-1,0 };

int map[MAX][MAX];
int n, x, y, d, g;
void print() {
	F(y, 10) {
		F(x, 10) {
			cout << map[y][x];
		}cout << '\n';
	}cout << "\n\n";
}
int count_square() {
	int ans = 0;
	F(y, MAX) F(x, MAX) {
		if (!map[y][x] || !map[y][x + 1] ||
			!map[y + 1][x] || !map[y + 1][x + 1]) continue;
		ans++;
	}
	return ans;
}
void check_square(int cmap[][MAX]) {
	F(y, MAX) F(x, MAX) {
		map[y][x] = map[y][x] | cmap[y][x];
	}
}
void rotate(vii v) {
	int y = v.back().first, x = v.back().second;
	int way;
	int vsize = v.size();
	for(int i = vsize - 2; i >= 0 ; --i){

		int by = v[i + 1].first, bx = v[i + 1].second;
		int ty = v[i].first, tx = v[i].second;
		
		F(a, 4) {
			if (dx[a] != tx - bx || dy[a] != ty - by) continue;

			way = a - 1;
			way = (way + 4) % 4;
			
			break;
		}
		int ny = y + dy[way], nx = x + dx[way];

		v.push_back({ nx, ny });
		map[ny][nx] = true;
	}
}
int main() {
	// x,y 드래곤 커브 시작점, d 방향, g 세대
	int t; cin >> t;
	while (t--) {
		cin >> x >> y >> d >> g;

		vii v;
		int ny = y + dy[d], nx = x + dx[d];
		v.push_back({ x, y });
		v.push_back({ nx, ny });
		map[y][x] = map[ny][nx] = true;

		F(i, g) rotate(v);
	}

	print();

	cout << count_square() << '\n';
	return 0;
}