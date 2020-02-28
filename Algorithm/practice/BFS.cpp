#include "BFS.h"
using namespace std;

void BFS::q2206()
{
	int n, m;
	cin >> n >> m;

	int map[101][101] = { 0, }, visited[101][101][2] = { 0, };
	char ch;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> ch;
			map[x][y] = ch - 48;
		}
	}

	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	// plz use tuple like this >> queue<tuple<int,int,int>> q;

	queue<tuple<int, int, int>> q;


	q.push(make_tuple(0, 0, 0));
	visited[0][0][0] = 1;

	//bool done = false, countBreak = false;
	while (!q.empty()) {

		//int tempX = q.front().first;
		//int tempY = q.front().second;
		int tx, ty, tz;
		tie(tx, ty, tz) = q.front();
		q.pop();
		//cout << "starting : " << tx << ", " << ty << "\n\n";

		for (int a = 0; a < 4; a++)
		{
			int nx = dx[a] + tx;
			int ny = dy[a] + ty;

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (map[nx][ny] == 0 && visited[nx][ny][tz] == 0) {
					visited[nx][ny][tz] = visited[tx][ty][tz] + 1;
					q.push(make_tuple(nx, ny, tz));
				}
				if (map[nx][ny] == 1 && tz == 0 && visited[nx][ny][tz + 1] == 0) {
					visited[nx][ny][tz + 1] = visited[tx][ty][tz] + 1;
					q.push(make_tuple(nx, ny, tz + 1));
				}
			}
		}
	}
	if (visited[n - 1][m - 1][0] != 0 && visited[n - 1][m - 1][1] != 0) {
		cout << min(visited[n - 1][m - 1][0], visited[n - 1][m - 1][1]);
	}
	else if (visited[n - 1][m - 1][0] != 0)
		cout << visited[n - 1][m - 1][0];
	else if (visited[n - 1][m - 1][1])
		cout << visited[n - 1][m - 1][1];
	else
		cout << -1;
}

void BFS::q5382()
{
	int test_case;
	cin >> test_case;
	vector<int> v;

	for (int tcase = 0; tcase < test_case; ++tcase)
	{
		int h, w, d;
		cin >> h >> w >> d;

		/*
‘S’, the starting position of the ship.
‘.’, water.
‘#’, land.
‘@’, a drawbridge.
		*/
		int dx[] = { -1,1,0,0 };
		int dy[] = { 0,0,-1,1 };

		queue<pair<int, int>> q;
		char map[51][51];
		int visited[51][51], delayTime;

		for (int x = 0; x < h; x++) {
			for (int y = 0; y < w; y++) {
				visited[x][y] = 0;
				cin >> map[x][y];
				if (map[x][y] == 'S') {
					q.push(make_pair(x, y));
					visited[x][y] = 1;
				}
			}
		}

		delayTime = d;
		while (!q.empty()) {
			int tx = q.front().first;
			int ty = q.front().second;
			q.pop();

			if (tx == h - 1 || tx == 0 || ty == w - 1 || ty == 0) {
				v.push_back(visited[tx][ty]);
				break;
			}

			for (int a = 0; a < 4; a++) {
				int nx = dx[a] + tx;
				int ny = dy[a] + ty;

				if (nx >= 0 && ny >= 0 && nx < h && ny < w && map[nx][ny] != '#' && map[nx][ny] != 'S') {
					if (map[nx][ny] == '.') {
						map[nx][ny] = '#';
						visited[nx][ny] = visited[tx][ty] + 1;
						q.push(make_pair(nx, ny));
					}

					if (map[nx][ny] == '@' && delayTime > 0) {
						delayTime--;
						if (delayTime == 0) {
							map[nx][ny] = '#';
							visited[nx][ny] = visited[tx][ty] + d + 1;
							q.push(make_pair(nx, ny));
							delayTime = d;
						}
						else {
							q.push(make_pair(tx, ty));
						}
					}
					//cout << "visiting : " << nx << ", " << ny << ", " << visited[nx][ny] << '\n';
				}
			}
		}
		//for (int x = 0; x < h; x++) {
		//	for (int y = 0; y < w; y++) {
		//		cout << visited[x][y] << " ";
		//	}cout << endl;
		//}
		//cout << endl << endl;

	}
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i);
		if (i < v.size() - 1)
			cout << '\n';
	}
}
/*

#######
#..S12#
#@#6#3#
#...54#
#@.####
#...###
##...##
#.....#
#@#@#.#
#.....#
#@#.###
#.#.###
###...#
#.....#
#@#@#.#
#.....#
#@#..##
####.##
#.....#
#@#@#.#
#.....#
#@#.###
#.#####

#.#####

*/

void BFS::q17300()
{
	int n;
	cin >> n;
	bool nextNumFound = false, sameNum = false;
	int map[4][4] = { 0, }, xpos[12], ypos[12], temp[12];

	for (int i = 1; i <= n; i++) {
		cin >> temp[i];
		xpos[i] = (temp[i] - 1) / 3;
		ypos[i] = (temp[i] - 1) % 3;
		map[xpos[i]][ypos[i]] = i;
	}

	sort(temp+1, temp + n+1);

	for (int i = 1; i < n; i++) {
		if (temp[i] == temp[i + 1])
			sameNum = true;
			//goto A;
	}
	int dx[] = { -1, 1,0,0, 1,1,-1,-1,2, 2, 1, 1, -1, -1, -2, -2 };
	int dy[] = { 0,0,-1,1, 1,-1,1,-1,1,-1, 2,-2, 2, -2, 1, -1 };
	int dxx[] = { -2,2,0,0,-2,-2,2,2 };
	int dyy[] = { 0,0,-2,2,2,-2,2,-2 };

	if (!sameNum) {
		for (int i = 1; i < n; i++) {
			nextNumFound = false;
			for (int a = 0; a < 16; a++) {
				int nx = dx[a] + xpos[i];
				int ny = dy[a] + ypos[i];

				if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3 && map[nx][ny] > 1 && map[nx][ny] < i + 2) {
					//cout << "checking : " << nx << ", " << ny << '\n';
					if (map[nx][ny] == i + 1) {
						//cout << "cchecking : " << nx << ", " << ny << ", " << map[nx][ny] << '\n';
						nextNumFound = true;
						break;
					}
					else if (map[nx][ny] != i + 1) {

						for (int b = 0; b < 8; b++) {
							int nxx = dxx[b] + xpos[i];
							int nyy = dyy[b] + ypos[i];

							if (nxx >= 0 && nyy >= 0 && nxx < 3 && nyy < 3 && map[nxx][nyy] == i + 1) {
								nextNumFound = true;
								//cout << "ccchecking : " << nxx << ", " << nyy << ", " << map[nxx][nyy] << '\n';
								break;
							}
						}
					}
				}
			}
			if (!nextNumFound) break;
		}
		//for (int x = 0; x < 3; x++)
		//{
		//	for (int y = 0; y < 3; y++)
		//	{
		//		cout << map[x][y];
		//	}cout << endl;
		//}
	}
	//A:
	if (nextNumFound) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}
void BFS::q1012()
{
	int test_case, T;
	cin >> T;
	vector<int> v;
	for (test_case = 0; test_case < T; test_case++)
	{
		int m, n, k;
		cin >> m >> n >> k;

		//vector<pair<int, int>> v;
		int map[52][52] = { 0, }, result = 0;
		bool visited[52][52] = { false, };
		for (int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}
		//for (int y = 0; y < n; y++) {
		//	for (int x = 0; x < m; x++) {
		//		cout << map[y][x];
		//	}cout << endl;
		//}

		int dx[] = { -1,1,0,0 };
		int dy[] = { 0,0,-1,1 };
		queue<pair<int, int>> q;

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (!visited[y][x]) {
					visited[y][x] = true;
					if (map[y][x] == 1) {
						map[y][x] = 2;
						result++;
						q.push(make_pair(y, x));

						while (!q.empty()) {
							int ty = q.front().first;
							int tx = q.front().second;
							q.pop();
							for (int a = 0; a < 4; a++) {
								int nx = dx[a] + tx;
								int ny = dy[a] + ty;

								if (x < m && y < n && x >= 0 && y >= 0 && map[ny][nx] == 1 && !visited[ny][nx]) {
									map[ny][nx] = 2;
									visited[ny][nx] = true;
									q.push(make_pair(ny, nx));
								}
							}
						}
					}
				}
			}
		}

		//cout << result <<'\n';
		v.push_back(result);
	}


	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i);
		if (i != v.size() - 1) cout << '\n';
	}

}


void BFS::q5014()
{
	//F 층, 현재 S층, G층이 목표
	//위로 U 씩. 아래로 D 씩
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	int dt[] = { U ,-D };

	int visited[1000001] = { 0, };
	queue<int> q;
	q.push(S);
	visited[S] = 1;

	while (!q.empty()) {
		
		int pos = q.front();
		q.pop();

		if (pos == G || (!D && !U)) break;
		cout << "visiting : " << pos << '\n';

		for (int a = 0; a < 2; a++) {
			int npos = pos + dt[a];

			//if (npos == G) break;
			if (npos < 1 || npos > F || visited[npos] || npos > 1000000) continue;

			visited[npos] = visited[pos] + 1;
			q.push(npos);
		}
		


/*
		else if (G > t) {
			if (!U) break;
			if (t + U > 1000000 || t + U > F) {
				visited[t - D] = visited[t] + 1;
				q.push(t - D);
				continue;
			}
			visited[t + U] = visited[t] + 1;
			q.push(t + U);
		}
		else if (G < t) {
			if (!D) break;
			if (t - D < 0 ||) {
				visited[t + U] = visited[t] + 1;
				q.push(t + U);
				continue;
			}
			visited[t - D] = visited[t] + 1;
			q.push(t - D);
		}*/
	}

	if (visited[G]) cout << visited[G];
	else cout << "use the stairs";

}
void BFS::q2644()
{
	int n, x, y, m;
	cin >> n >> x >> y >> m;

	vector<int> v[101];
	int visited[101] = { 0, };

	for (int i = 0; i < m; i++) {
		int tx, ty;
		cin >> tx >> ty;
		v[tx].push_back(ty);
		v[ty].push_back(tx);
	} 
	
	queue<int> q;
	q.push(x);
	visited[x] = 0;

	while (!q.empty()) {
		int tx = q.front();
		q.pop();

		cout << "checking : tx " << tx << "\n";
		int size = v[tx].size();
		for (int i = 0; i < size; i++) {
			int nx = v[tx].at(i);
			cout << "nx : " << nx << '\n';

			if (!visited[nx]) {
				visited[nx] = visited[tx] + 1;
				q.push(nx);
				//if (nx == y) {
				//	visited[x][y]++; break;
				//}
				cout << "pushing : " << nx << '\n';
			}
		}cout << '\n';
	}
	if (!visited[y]) cout << -1;
	else cout << visited[y];
}



void BFS::q2573()
{
	int waterCnt[301][301];
	int visited[301][301];
	int map[301][301];

	int n, m, result = 0;
	cin >> n >> m;
	map[301][301] = { 0, };
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
		}
	}

	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	bool noWater = true;
	int glacierNum = 0;
	//count glacier num
	while (true) {
		memset(visited, 0, sizeof(visited));
		glacierNum = 0;

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (noWater && !map[y][x]) noWater = false;
				if (!map[y][x] || visited[y][x]) continue;
				visited[y][x] = 1;
				glacierNum++;

				//cout << "chekcing : " << y << ", " << x << '\n' << "visited ? : " << visited[y][x] << '\n';
				queue<pair<int, int>> q;
				q.push(make_pair(y, x));

				while (!q.empty()) {
					int ty = q.front().first;
					int tx = q.front().second;
					q.pop();

					for (int a = 0; a < 4; a++) {
						int ny = dy[a] + ty;
						int nx = dx[a] + tx;

						if (nx < 0 || ny < 0 || ny >= n || nx >= m || map[ny][nx]==0 || visited[ny][nx]) continue;

						visited[ny][nx] = 1;
						q.push(make_pair(ny, nx));
					}
				}
			}
		}

		if (glacierNum >= 2) break;
		else if (!glacierNum) break;

		//count surround water num
		memset(waterCnt, 0, sizeof(waterCnt));
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (!map[y][x]) continue;

				for (int a = 0; a < 4; a++) {
					int ny = dy[a] + y;
					int nx = dx[a] + x;
					if (nx < 0 || ny < 0 || ny >= n || nx >= m) continue;
					if (map[ny][nx] == 0) waterCnt[y][x]++;
				}
			}
		}

		if (noWater) break;

		cout << '\n';
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				map[y][x] -= waterCnt[y][x];
				if (map[y][x] < 0) map[y][x] = 0;
				cout << map[y][x] << " ";
			}cout << '\n';
		}

		result++;
	}
	if (!glacierNum || noWater) cout << 0;
	else cout << result;
	/*

	5 7
	0 0 0 0 0 0 0
	0 10 10 10 10 10 0
	0 10 10 0 10 10 0
	0 10 10 0 10 10 0
	0 0 0 0 0 0 0

	5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 0 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0

5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0

	*/
}

//int map[201][201];
//int visited[201][201][31] = { 0, };
//int step[][3] = {
//	{-2,1,1},{-1,2,1},{1,2,1},{2,1,1},
//	{2,-1,1},{1,-2,1},{-1,-2,1},{-2,-2,1},
//	{-1,0,0}, {0,1,0},
//	{1,0,0}, {-1,0,0},
//};

void BFS::q1600()
{
	int map[201][201];
	int visited[201][201][31];
	int step[][3] = {
		{-2,1,1},{-1,2,1},{1,2,1},{2,1,1},
		{2,-1,1},{1,-2,1},{-1,-2,1},{-2,-2,1},
		{-1,0,0}, {0,1,0},
		{1,0,0}, {-1,0,0},
	};
	int result = 65535;

	int k, w, h;
	cin >> k >> w >> h;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			cin >> map[y][x];
		}
	}

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	visited[0][0][0] = 0;
	bool done = false;
	while (!q.empty()) {
		int ty, tx, tz;
		tie(ty, tx, tz) = q.front();
		q.pop();
		//cout << "start : " << ty << ", " << tx << ", " << tz << '\n';
		for (int a = 0; a < 12; a++) {
			int ny = step[a][0] + ty;
			int nx = step[a][1] + tx;
			int nz = step[a][2] + tz;

			if (ny < 0 || nx < 0 || ny >= h || nx >= w || map[ny][nx]==1 || nz > k || visited[ny][nx][nz]) continue;

			visited[ny][nx][nz] = visited[ty][tx][tz] + 1;
			q.push(make_tuple(ny, nx, nz));
			
			if (ny == h - 1 && nx == w - 1) {
				result = visited[ny][nx][nz];
				done = true;
				break;
			}
			//cout << "push : " << ny << ", " << nx << ", " << nz << '\n';
		}if (done) break;
	}
	
	//cout << endl << endl;
	//for (int y = 0; y < h; y++) {
	//	for (int x = 0; x < w; x++) {
	//		cout << visited[y][x][1];
	//	}cout << endl;
	//}
	//cout << endl << endl;

	//for (int i = 0; i <= k; i++)
	//	result = min(result, visited[h - 1][w - 1][i]);
	//if (result > 60000)	result = -1;
	//cout << result;

	if (done) cout << result;
	else cout << -1;
}

void BFS::q3187()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int r, c;
	cin >> r >> c;

	char map[251][251];
	bool visited[251][251];
	
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			cin >> map[y][x];
			visited[y][x] = false;
		}
	}
	
	int dy[] = { -1,1,0,0 };
	int dx[] = { 0,0,-1,1 };

	int sheepCnt = 0, wolfCnt = 0;

	for (int y = 0; y < r; y++){
		for (int x = 0; x < c; x++) {
			if (map[y][x] == '#' || visited[y][x]) continue;
			visited[y][x] = true;

			queue<pair<int, int>> q;
			q.push(make_pair(y, x));

			//cout << "checking : " << y << ", " << x << '\n';
			int sheepCntTemp = 0, wolfCntTemp = 0;
			
			while (!q.empty()) {
				int ty = q.front().first;
				int tx = q.front().second;
				q.pop();

				if (map[ty][tx] == 'k')
					sheepCntTemp++;
				else if (map[ty][tx] == 'v')
					wolfCntTemp++;

				for (int a = 0; a < 4; a++) {
					int ny = dy[a] + ty;
					int nx = dx[a] + tx;

					if (ny < 0 || nx < 0 || ny >= r || nx >= c || map[ny][nx] == '#' || visited[ny][nx])   continue;

					visited[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}
			}
				//양 > 늑대 -> 양만 생존
				if (sheepCntTemp > wolfCntTemp)
					sheepCnt += sheepCntTemp;
				//else 늑대만 생존
				else
					wolfCnt += wolfCntTemp;
		}
	}
	
	cout << sheepCnt << " " << wolfCnt << '\n';

}

void BFS::q9205()
{
	/*
	맥주 한박스 = 20병
	50미터당 1병
	*/
	std::ios_base::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int T, test_case;
	std::cin >> T;
	for (test_case = 0; test_case < T; ++test_case) {

		int n, pos[104][2];
		bool visited[104];
		memset(pos, 0, sizeof(pos));
		memset(visited, 0, sizeof(visited));

		std::cin >> n;
		for (int i = 0; i < n+2; i++){
			cin >> pos[i][0] >> pos[i][1];
		}

		

		std::queue<std::pair<int, int>> q;
		q.push(make_pair(pos[0][0], pos[0][1]));
		visited[0] = true;


		bool happy = false;
		while (!q.empty()) {
			int tx = q.front().first;
			int ty = q.front().second;
			q.pop();

			if (tx == pos[n + 1][0] && ty == pos[n + 1][1]) {
				happy = true;
				break;
			}

			for (int j = 1; j < n + 2; j++) {
				int nx = pos[j][0];
				int ny = pos[j][1];

				if (abs(nx - tx) + abs(ny - ty) > 1000) continue;

				visited[j] = true;
				q.push(std::make_pair(nx, ny));
			}
		}
		if (happy) std::cout << "happy" << '\n';
		else std::cout << "sad" << '\n';
	}

	
/*
4
2
0 0
1000 0
1000 1000
2000 1000
2
0 0
1000 0
2000 1000
2000 2000
2
0 0
1000 0
1000 1000
2000 1000
2
0 0
1000 0
2000 1000
2000 2000
*/
}
int len4991 = 987654321;
void dfs4991(int a, std::vector<std::pair<int,int>> v, int dist[12][12], int visit[12], int result) {
	for (int i = 0; i < v.size(); i++) {
		if (visit[i]) continue;

		visit[i] += dist[a][i];
		cout << a << ", " << i << ", len : " << dist[a][i] << '\n';
		dfs4991(i, v, dist, visit, result);
		std::cout << visit[i] << '\n';
		visit[i] -= dist[a][i];
	}
	len4991 = min(len4991, visit[a]);
	cout << "done";
}

void BFS::q2468()
{
	int n, maxHeight = 0;
	std::cin >> n;
	
	int map[101][101];

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			std::cin >> map[y][x];
			if (maxHeight < map[y][x]) maxHeight = map[y][x];
		}
	}

	int dy[] = { -1,0,1,0 };
	int dx[] = { 0,1,0,-1 };

	int time = 0, maxSafeArea = 0;
	
	//count safeArea by time
	while (time <= maxHeight) {
		int safeArea = 0;
		int visited[101][101];
		memset(visited, 0, sizeof(visited));

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (map[y][x] <= time || visited[y][x]) continue;
				safeArea++;

				std::queue<std::pair<int, int>> q;
				q.push({ y, x });
				visited[y][x] = 1;

				while (!q.empty()) {
					int ty = q.front().first;
					int tx = q.front().second;
					q.pop();

					for (int a = 0; a < 4; a++) {
						int ny = dy[a] + ty;
						int nx = dx[a] + tx;

						if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || map[ny][nx] <= time) continue;
						q.push({ ny,nx });
						visited[ny][nx] = 1;
					}
				}
			}
		}

		time++;
		maxSafeArea < safeArea ?
			maxSafeArea = safeArea : maxSafeArea;
	}
	std::cout << maxSafeArea;
}


void BFS::q1963()
{
	int test_case, T;
	std::cin >> T;

	bool prime[10005];
	memset(prime, true, sizeof(prime));

	for (int i = 2; i < 10000; i++) {
		for (int j = i * 2; j < 10000; j += i)
				prime[j] = false;
	}

	
	for (test_case = 1; test_case <= T; ++test_case) {

		int n, k, result = 10000;
		std::cin >> n >> k;
		
		string start, end;
		start = to_string(n);
		end = to_string(k);

		std::vector<string> v;
		v.clear();

		for (int i = n; i <= k; i++) {
			if (prime[i]) {
				v.push_back(to_string(i));
				//cout << i << '\n';
			}
		}


		bool impossible = true;
		int size = v.size();
		int diffCnt;

		if (n == k) {
			result = 1;
			impossible = false;
		}
		else{
				int visit[10000];
				memset(visit, 0, sizeof(visit));

				std::queue<std::pair<string, int>> q;
				q.push({ start, 1 });
				visit[0] = 1;

				while (!q.empty()) {
					string ts = q.front().first;
					int tt = q.front().second;
					q.pop();

					//std::cout << "visiting : " << ts << ", " << tt <<'\n';

					if (ts == end) {
						impossible = false;
						result > tt ?
							result = tt : result;
					}

					for (int i = 0; i < size; i++) {
						if (visit[i]) continue;
						diffCnt = 0;
						for (int a = 0; a < 4; a++)
							if (ts[a] != v.at(i)[a]) 
								diffCnt++;
						if (diffCnt != 1) continue;

						q.push({ v.at(i), tt + 1 });
						visit[i] = 1;
					}
				
			}
		}
		if(!impossible) std::cout << result - 1 << '\n';
		else std::cout << "Impossible" << '\n';
	}
}











//12:00
void BFS::q4991()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int dy[] = { -1,1,0,0 };
	int dx[] = { 0,0,-1,1 };

	while (true) {
		int w, h;
		std::cin >> w >> h;
		if (w == 0 && h == 0) break;
		
		
		std::vector<std::pair<int, int>> v;
		char map[21][21];
		memset(map, 0, sizeof(map));

		int trashCnt = 0, result = 0, trashNum[21][21], dist[12][12], startY, startX;
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				std::cin >> map[y][x];

				if (map[y][x] == 'o') {
					startY = y;
					startX = x;
					map[y][x] = '*';
				}
				else if (map[y][x] == '*') {
					v.push_back(std::make_pair(y, x));
					trashNum[y][x] = trashCnt++;
				}
			}
		}

		v.push_back(std::make_pair(startY, startX));
		trashNum[startY][startX] = trashCnt;

		//bfss
		for (int i = 0; i < v.size(); i++) {
			int y = v.at(i).first;
			int x = v.at(i).second;

			std::queue<std::pair<int, int>> q;
			q.push(std::make_pair(y, x));

			int visited[21][21];
			memset(visited, 0, sizeof(visited));

			while (!q.empty()) {
				int ty = q.front().first;
				int tx = q.front().second;
				q.pop();
				//cout << "check : " << ty << ", " << tx << '\n';

				for (int a = 0; a < 4; a++) {
					int ny = dy[a] + ty;
					int nx = dx[a] + tx;

					if (ny < 0 || nx < 0 || ny >= h || nx >= w || visited[ny][nx] || map[ny][nx] == 'x') continue;

					//cout << "ccheck : " << ny << ", " << nx << '\n';

					visited[ny][nx] = visited[ty][tx] + 1;
					q.push(std::make_pair(ny, nx));

					if (map[ny][nx] == '*') {
						dist[i][trashNum[ny][nx]] = visited[ny][nx];
					}
				}

				//if (!trashCnt) break;
			}
		}



		//dfs
		int visit[12] = { 0, };

		dfs4991(v.size()-1, v, dist, visit, result);

		if (!trashCnt) std::cout << -1 << "\n";
		std::cout << len4991 << '\n';

		cout << "\n\n";
	}
}

void BFS::q11460()
{
	//22까지 countable

}


/*
8
1 5 9 8 7 3 6 4

4
1 4 5 1
*/