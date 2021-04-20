#include <iostream>
#include <queue>
#include <string>
#define F(i,n) for(int i = 0 ; i < n ;++i)
#define MAX 101
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
struct P { int x, y; };
int n, m;
string s;
int map[MAX][MAX];
int visit[MAX][MAX];
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= m || y >= n);
}
void print() {
	F(x, m) {
		F(y, n) {
			if (visit[x][y] != 1e9)	cout << visit[x][y] << " ";
			else					cout << "- ";
		} cout << '\n';
	}cout << '\n';
}
void print(bool tt) {
	F(x, m) {
		F(y, n) {
			cout << map[x][y] << " ";
		} cout << '\n';
	}cout << '\n';
}
void bfs() {
	queue<P> q;
	q.push({ 0,0 });
	visit[0][0] = 0;

	while (!q.empty()) {
		//print();
		int tx = q.front().x, ty = q.front().y;
		q.pop();

		F(a, 4) {
			int nx = tx + dx[a], ny = ty + dy[a];
			if (!check(nx, ny)) continue;

			if (map[nx][ny] == 0) {
				if (visit[nx][ny] > visit[tx][ty]) {
					visit[nx][ny] = visit[tx][ty];
					q.push({ nx, ny });
				}
			}
			else {
				if (visit[nx][ny] > visit[tx][ty] + 1) {
					visit[nx][ny] = visit[tx][ty] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	F(x, m) {
		cin >> s;
		F(y, n) {
			map[x][y] = s[y] - '0';
			visit[x][y] = 1e9;
		}
	}
	//print(true);
	bfs();

	cout << visit[m - 1][n - 1];
	return 0;
}