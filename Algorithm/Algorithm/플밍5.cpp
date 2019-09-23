#include <iostream>
#include <queue>

using namespace std;
int dy[2] = { 0,1 };  int dx[2] = { 1,0 };
int main(void) {
	int answer = 0;
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	int visit[25][25] = { 0, };
	queue<pair<int, int>> q;
	q.push({ 0,0 });

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int a = 0; a < 2; a++) {
			int ny = ty + dy[a];
			int nx = tx + dx[a];

			if (ny == y && nx == x) answer += 1;
			else if (ny > y || nx > x) continue;
			else {
				q.push({ nx,ny });
				visit[nx][ny] = visit[tx][ty] + 1;
			}
		}

	}
	if (!answer) cout << "fail";
	else cout << answer << '\n' << visit[x][y-1]+1;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cout << visit[y][x];
		}cout << endl;
	}


	return 0;
}