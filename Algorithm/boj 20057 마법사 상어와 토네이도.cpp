#include <iostream>
using namespace std;
#define MAX 500
#define F(i, n) for(int i = 0 ; i < n ; ++i)
int n, map[MAX][MAX], ans;
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int ddx[][10] = {
	{-2,-1,-1,-1,2,1,1,1,0,0}
	,{0,1,0,-1,0,1,0,-1,2,1}
	,{2,1,1,1,-2,-1,-1,-1,0,0}
	,{0,-1,0,1,0,-1,0,1,-2,-1}
};
int ddy[][10] = {
	{0,-1,0,1,0,-1,0,1,-2,-1}
	,{-2,-1,-1,-1,2,1,1,1,0,0}
	,{0,1,0,-1,0,1,0,-1,2,1}
	,{2,1,1,1,-2,-1,-1,-1,0,0}
};
int dd[] = {2,10,7,1,2,10,7,1,5};

bool chk(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}

void tornado(int x, int y, int d) {
	int out_sum = 0, sum = 0, s = map[x][y];

	F(a, 10) {
		int nx = x + ddx[d][a], ny = y + ddy[d][a], t;

		if (a == 9) {
			if (!chk(nx, ny))	out_sum += s - sum;
			else map[nx][ny] += (s - sum);
		}
		else {
			t = s * dd[a] / 100;
			if (!chk(nx, ny)) sum += t, out_sum += t;
			else sum += t, map[nx][ny] += t;
		}
	}
	ans += out_sum;
	map[x][y] = 0;
}

void rotate(int x, int y, int d, int len) {
	int nd = d, nx = x, ny = y;
	F(a, 2) F(l, len) {
		nd = (d + a) % 4, nx += dx[nd], ny += dy[nd];

		if (!chk(nx, ny)) return;
		tornado(nx, ny, nd);
	}
	rotate(nx, ny, (nd + 1) % 4, len + 1);
}

int main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	F(x, n) F(y, n) cin >> map[x][y];

	rotate(n/2, n/2, 0, 1);

	cout << ans;
	return 0;
}