// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRDL1aeugDFAUo&categoryId=AWXRDL1aeugDFAUo&categoryType=CODE
// 20200606 1852
// 20210419 1900
#include<iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
#pragma warning (disable:4996)
#define F(i, n) for(int i = 0 ; i < n ; ++i)
using namespace std;
int dx[] = { 0, -1,0,1,0 };
int dy[] = { 0,0,1,0,-1 };

struct Beacon { int x, y, len, power; };
struct User { int x, y; };
struct P { int x, y; };

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= 10 || y >= 10);
}
void print(vector<int> map[][10]) {
	F(x, 10) {
		F(y, 10) {
			cout << map[x][y].front() << ' ';
		}cout << '\n';
	}
}
void print(int map[][10]) {
	F(x, 10) {
		F(y, 10) {
			cout << map[x][y] << ' ';
		}cout << '\n';
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		// init()
		int m, a, t1, t2, t3, t4;
		int power_sum[2]{};
		int dir[2][100]{};
		Beacon beacon[10]{};
		User u[2];
		vector<int> map[10][10]{};
		int visit[10][10]{};
		F(x, 10) F(y, 10) map[x][y].push_back(0);

		//20 3
		//2 2 3 2 2 2 2 3 3 4 4 3 2 2 3 3 3 2 2 3
		//4 4 1 4 4 1 4 4 1 1 1 4 1 4 3 3 3 3 3 3
		//4 4 1 100
		//7 10 3 40
		//6 3 2 70

		cin >> m >> a;
		F(i, m) cin >> dir[0][i];
		F(i, m) cin >> dir[1][i];
		F(i, a) { cin >> t1 >> t2 >> t3 >> t4; beacon[i + 1] = { t2 - 1, t1 - 1, t3, t4 }; }
		beacon[0] = { 0, 0, 0, 0 };
		u[0] = { 0,0 }, u[1] = { 9, 9 };
		visit[0][0] = 1, visit[9][9] = 2;

		// init_map()
		F(i, a) {
			queue<P> q; int visited[10][10]{};
			q.push({beacon[i+1].x, beacon[i+1].y});
			visited[beacon[i + 1].x][beacon[i + 1].y] = 1;
			map[beacon[i + 1].x][beacon[i + 1].y].push_back(i + 1);

			while (!q.empty()) {
				int tx = q.front().x, ty = q.front().y;
				q.pop();
				
				F(way, 4) {
					int nx = tx + dx[way + 1], ny = ty + dy[way + 1];

					if (!check(nx, ny) || visited[nx][ny]
						|| visited[tx][ty] == beacon[i + 1].len + 1) continue;
					
					q.push({ nx, ny });
					visited[nx][ny] = visited[tx][ty] + 1;
					map[nx][ny].push_back(i + 1);
				}
			}
		}

		// init_map_sort() 높은 번호가 먼저 나오게끔
		F(x, 10) F(y, 10) {
			sort(map[x][y].begin(), map[x][y].end(), [=](int xx, int yy)
			{ return beacon[xx].power > beacon[yy].power; });
		}

		//print(map);

		// init_charge()
		//if (map[0][0]) u1_sum += b[map[0][0]].power;
		//if (map[9][9]) u2_sum += b[map[0][0]].power;
		power_sum[0] += beacon[map[0][0].front()].power;
		power_sum[1] += beacon[map[9][9].front()].power;


		// move()
		F(move, m) {
			//cout << "move : " << move << '\n';
			//print(visit);

			int nx[2], ny[2];
			F(user, 2) {
				u[user].x += dx[dir[user][move]], u[user].y += dy[dir[user][move]];
				nx[user] = u[user].x, ny[user] = u[user].y;
				visit[nx[user]][ny[user]] = user + 1;
				//cout << user << " : " << nx[user] << ", " << ny[user] << '\n';
			}

			// 같은 비콘위에 서있는지 확인
			bool has_same_beacon = false;
			int beacon_standing_on[2]{};
			if (map[nx[0]][ny[0]].front() && map[nx[1]][ny[1]].front()) {
				F(i, (int)map[nx[0]][ny[0]].size()) {
					F(j, (int)map[nx[1]][ny[1]].size()) {
						if (map[nx[0]][ny[0]][i] == 0 || map[nx[1]][ny[1]][j] == 0) continue;
						if (map[nx[0]][ny[0]][i] == map[nx[1]][ny[1]][j]) {
							beacon_standing_on[0] = map[nx[0]][ny[0]][i];
							beacon_standing_on[1] = map[nx[1]][ny[1]][j];
							has_same_beacon = true;
							break;
						}
					}
					if (has_same_beacon) break;
				}
			}

			int i[2]{};
			if (has_same_beacon) {
				do {
					if (beacon[map[nx[0]][ny[0]][i[0]]].power == beacon[map[nx[1]][ny[1]][i[1]]].power) {
						if (map[nx[0]][ny[0]].size() > 1 && map[nx[1]][ny[1]].size() > 1) {
							if (beacon[map[nx[0]][ny[0]][i[0] + 1]].power > beacon[map[nx[1]][ny[1]][i[1] + 1]].power)
								i[0]++;
							else i[1]++;
						}
						else if (map[nx[0]][ny[0]].size() > 1) {
							i[0]++;
						}
						else if (map[nx[1]][ny[1]].size() > 1) {
							i[1]++;
						}
					}
						
				} while (beacon[map[nx[0]][ny[0]][i[0]]].power == beacon[map[nx[1]][ny[1]][i[1]]].power);

				power_sum[0] += beacon[map[nx[0]][ny[0]][i[0]]].power;
				power_sum[1] += beacon[map[nx[1]][ny[1]][i[1]]].power;
			}
			else {
				power_sum[0] += beacon[map[nx[0]][ny[0]][i[0]]].power;
				power_sum[1] += beacon[map[nx[1]][ny[1]][i[1]]].power;
			}
			//cout << "1 power : " << beacon[map[nx[0]][ny[0]][i[0]]].power << "\t2 power : " << beacon[map[nx[1]][ny[1]][i[1]]].power << '\n';
		}

		cout << "#" << test_case << " " << power_sum[0] + power_sum[1] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}