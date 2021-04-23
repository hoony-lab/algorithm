#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
struct P { int x,y,d; };
using namespace std;
int dx[] = { 0,0,-1,0,1 };
int dy[] = { 0,1,0,-1,0 };
int w, h, n;
long long ans;
map<int, P> kunai;
vector<vector<int>> m, visit;
void print(vector<vector<int>> m) {
	F(x, h) { F(y, w) { cout << m[x][y] << " "; } cout << '\n'; }cout << '\n';
}
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= h || y >= w);
}

int main() {
	cin >> w >> h >> n;
	vector<vector<int>> tm(h, vector<int>(w, 0)), tv(h, vector<int>(w, 0));
	m = tm, visit = tv;
	
	F(i, n) {
		int x, y, d;
		cin >> x >> y >> d;
		
		// 맵에 현재 어느 위치에 쿠나이번호
		m[y - 1][x - 1] = i + 1;
		// 쿠나이번호에 해당하는 map
		kunai[i + 1] = { y - 1, x - 1, d + 1 };
		// 색칠된 정사각형, 바로 카운트
		visit[y - 1][x - 1] = i + 1, ans++;
	}

	// 충분한 시간
	while (1) {
		cout << "\t===TIME===\n";
		print(m);
		print(visit);
		map<int, P> tkunai = kunai;

		for(pair<int, P> ku : tkunai) {
			int tx = ku.second.x, ty = ku.second.y, td = ku.second.d, ti = ku.first;
			int nx = tx + dx[td], ny = ty + dy[td];

			// 벽 밖
			if (!check(nx, ny)) {
				kunai.erase(ti);
				continue;
			}
			// 벽 안: 0
			if()

			// 벽 안 : 마주보기





			cout << "\tstart : " << tx << ", " << ty << ", " << td << '\n';
			// 없어진 쿠나이면 패쓰
			if (td == 0) continue;
			
			int nx = tx + dx[td], ny = ty + dy[td], ni = m[nx][ny];
			cout << "\t\tgo : " << nx << ", " << ny << ", " << '\n';
			// 갈자리에 쿠나이 있으면 패쓰

			if (!check(nx, ny)) continue;
			cout << "\t\t\tgo : " << nx << ", " << ny << ", " << '\n';

			bool gonna_meet = false;
			F(a, 5) if(a) {
				// 서로 방향이 같으면 : 둘다 소멸
				if (td == a && kunai[ni].d == (td + 2 - 1) % 4 + 1) {
					cout << "\t\t\tmeet : " << a << ", " << kunai[ni].d << '\n';
					kunai[i + 1].d = 0;
					//kunai[ni].d = 0;
					m[tx][ty] = 0, m[nx][ny] = 0;
					visit[nx][ny] += i + 1, ans++;
					
					gonna_meet = true;
				}
			}

			if (!gonna_meet) {
				// 서로 방향이 다르면
				kunai[i + 1] = { nx, ny, td };
				m[tx][ty] = 0, m[nx][ny] = i + 1;

				// 첫 방문
				if (!visit[nx][ny]) {
					visit[nx][ny] += i + 1, ans++;
				}
			}
			
		}
	}

	cout << ans;
	return 0;
}