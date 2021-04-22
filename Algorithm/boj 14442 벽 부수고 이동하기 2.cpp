#include <iostream>
#include <queue>
#include <string>
#define MAX 1001
#define F(i, n) for(int i = 0 ; i < n ; ++i)
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct P { int x, y, z; };
int n, m, k, map[MAX][MAX], visit[MAX][MAX][11], min_dist = 1e9;

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= m);
}
void print(int i) {
	F(x, n) {
		F(y, m) {
			cout << visit[x][y][i] << " ";
		}cout << '\n';
	}cout << '\n';
}
void print() {
	F(x, n) {
		F(y, m) {
			cout << map[x][y] << " ";
		}cout << '\n';
	}cout << '\n';
}
int main() {
	cin >> n >> m >> k;
	F(x, n) {
		string s;	cin >> s;
		F(y, m) map[x][y] = s[y] - '0';
	}
	F(x, n) F(y, m) F(i, k + 1) visit[x][y][i] = 1e9;

	queue<P> q;
	q.push({ 0,0,0 }); visit[0][0][0] = 1;
	
	while (!q.empty()) {
		int tx = q.front().x, ty = q.front().y, tz = q.front().z;
		q.pop();
		//cout << "start : " << tx << ", " << ty << '\n';
		F(a, 4) {
			int nx = tx + dx[a], ny = ty + dy[a];
			//cout << "\tc : " << nx << ", " << ny << '\n';
			if (!check(nx, ny) || visit[nx][ny][tz] != 1e9) continue;

			if (map[nx][ny] == 0) {
				q.push({ nx, ny, tz });
				visit[nx][ny][tz] = visit[tx][ty][tz] + 1;
			}

			if(map[nx][ny] == 1) {
				//cout << "\tbreak : " << nx << ", " << ny << '\n';
				if (tz >= k) continue;
				
				q.push({ nx, ny, tz + 1 });
				visit[nx][ny][tz + 1] = visit[tx][ty][tz] + 1;
			}
		}
	}

	//print(0);
	//print(1);

	F(i, k + 1) if(visit[n-1][m-1][i] != 1e9) 
		min_dist = min(min_dist, visit[n - 1][m - 1][i]);

	if (min_dist == 1e9) cout << "-1";
	else cout << min_dist;

	return 0;
}