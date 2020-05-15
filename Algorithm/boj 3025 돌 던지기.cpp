#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define FIO	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define F(i, n) for(int i = 0 ;i < n ; ++i)
struct P { int x, y; };
//int dx[] = { 0, 1 };
//int dly[] = { -1, -1 };
//int dry[] = { 1, 1 };

int n, m;
char map[30001][31];
vector<P> block;
void print(char map[][31]) {
	F(x, n) {
		F(y, m) {
			cout << map[x][y];
		}
		cout << '\n';
	}
}

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= m);
}

int check_left_right(int x, int y) {
	bool left = true, right = true;
	F(a, 2) {
		int nx = x + a, ny = y - 1;
		if (!check(nx, ny) || map[nx][ny] != '.') left = false;
	}
	if (left) return  y - 1;

	F(a, 2) {
		int nx = x + a, ny = y + 1;
		if (!check(nx, ny) || map[nx][ny] != '.') right = false;
	}
	if (right) return y + 1 ;

	return y;
}

int go_down(int x, int y) {
	while (check(x, y) && map[x][y] == '.') x++;
	return x - 1;
}

int main() {
	FIO;
	cin >> n >> m;

	F(x, n) {
		F(y, m) {
			cin >> map[x][y];
			if (map[x][y] == 'X') block.push_back({ x,y });
		}
	}

	int t, c;
	cin >> t;
	while (t--) {
		cin >> c;

		int x = 0, y = c - 1;

		while (map[x][y] == '.' ) {
			//cout << x << ", " << y << '\n';
			x = go_down(x, y);
			int ny = check_left_right(x, y);

			if (y == ny) break;
			else y = ny;
		}
		map[x][y] = 'O';
	}

	print(map);

	return 0;

}