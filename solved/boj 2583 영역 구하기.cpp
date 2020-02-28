#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;

int map[102][102];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
vector<int> v;

int main() {

	int m, n, k;

	memset(map, 0, sizeof(map));
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 = min(x1, x2), x2 = max(x1, x2);
		y1 = min(y1, y2), y2 = max(y1, y2);

		for (int y = y1; y < y2; y++)
			for (int x = x1; x < x2; x++)
				map[y][x]++;
	}

	for (int y = 0; y < m; y++)	{
		for (int x = 0; x < n; x++){
			if (map[y][x] > 0) continue;

			int count = 1;
			map[y][x]++;

			queue<pair<int, int>> q;
			q.push({ y,x });

			while (!q.empty()) {
				int ty = q.front().first;
				int tx = q.front().second;
				q.pop();

				for (int a = 0; a < 4; a++){
					int ny = dy[a] + ty;
					int nx = dx[a] + tx;

					if (ny < 0 || nx < 0 || ny >= m || nx >= n || map[ny][nx] > 0) continue;

					count++;
					map[ny][nx]++;
					q.push({ ny,nx });

				}
			}	

			v.push_back(count);

		}
	}

	cout << v.size() << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";


}