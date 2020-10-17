// 20201017 1830 - 2030
#include<iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
#pragma warning (disable : 4996)
#define F(i, n) for (int i = 0 ; i < n ; ++i)
#define MAX 20
struct P { int x, y; };
int dx[] = { 1, 1, -1, -1 };
int dy[] = { 1, -1, -1, 1 };
int n, ans;
int map[MAX][MAX], eat[101], visit[MAX][MAX];
set<int> st;
void print_eat(int e[]) {
	cout << "eat list : ";
	F(i, 101) if (e[i]) cout << i << ", ";
	cout << '\n';
}
void print(int m[][MAX]) {
	F(x, n) {
		F(y, n) {
			cout << m[x][y] << " ";
		}cout << '\n';
	}cout << "\n\n";
}
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}



void dfs(int m[][MAX], int sx, int sy, int x, int y, int e[], int cnt, int d) {

	//cout << " V : " << x << ", " << y << " : cnt " << cnt << " , d : " << d << '\n';

	if (sx == x && sy == y && d == 3) {
		ans = max(ans, cnt);
		//cout << "  DONE : " << cnt << " >> " << ans << '\n';
		return;
	}

	/* 방향 : 직진 , 회전 */
	F(a, 2) {
		if (d + a == 4) continue;
		int nx = x + dx[d + a], ny = y + dy[d + a];

		//cout << "  V : " << nx << ", " << ny << " , d+a : " << d + a  << '\n';
		if (check(nx, ny) && !visit[nx][ny] && !e[m[nx][ny]]) {
			//cout << "   V : " << nx << ", " << ny << " , d+a : " << d + a << '\n';

			visit[nx][ny] = true;
			e[m[nx][ny]] = true;

			dfs(m, sx, sy, nx, ny, e, cnt + 1, d + a);

			e[m[nx][ny]] = false;
			visit[nx][ny] = false;
		}
		else if (sx == nx && sy == ny) {
			dfs(m, sx, sy, nx, ny, e, cnt, d + a);
		}
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
		memset(map, 0, sizeof(map));
		ans = 0;
		cin >> n;
		F(x, n) F(y, n) cin >> map[x][y];

		F(x, n) F(y, n) {
			//cout << "START /// " << x << ", " << y << '\n';
			memset(eat, 0, sizeof(eat));

			eat[map[x][y]] = true;
			dfs(map, x, y, x, y, eat, 1, 0);
			eat[map[x][y]] = false;
		}

		if (!ans) ans = -1;
		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


//// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
//// 20200606 1449
//#include <iostream>
//#include <set>
//#include <queue>
//#include <memory.h>
//using namespace std;
//#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
//#define MAX 21
//#define F(i, n) for(int i = 0 ; i < n ; ++i)
//
//struct P { int x, y, w, cnt; bool eat[101]{}; };
//int dx[] = { 1, 1,-1,-1 }, dy[] = { 1,-1,-1,1 };
//int map[MAX][MAX];
//int n, ans;
//
//bool check(int x, int y) {
//	return !(x < 0 || y < 0 || x >= n || y >= n);
//}
//
//void bfs(int x, int y) {
//	queue<P> q;
//
//	bool eat[101]{};
//	eat[map[x][y]] = true;
//	q.push({ x, y, 0, 1, eat });
//
//	while (!q.empty()) {
//		int tx = q.front().x, ty = q.front().y, tw = q.front().w;
//
//		bool teat[101]{};
//		memcpy(teat, q.front().eat, sizeof(teat));
//
//		int cnt = q.front().cnt;
//		q.pop();
//
//		// 두개의 방향만 갈 수 있음
//		F(a, 2) {
//			int nw = tw + a;
//			if (nw == 4) continue;
//
//			int nx = tx + dx[nw], ny = ty + dy[nw];
//			if (!check(nx, ny) || nx < x) continue;
//
//			if (nx == x && ny == y) {
//				F(i, 10) {
//					cout << teat[i] << ", ";
//				}cout << '\n';
//				ans = max(ans, cnt);
//				continue;
//			}
//
//			if (teat[map[nx][ny]]) continue;
//
//			// cout << "nx, ny : " << nx << ", " << ny << " << " <<  tst.size() << " : " << map[nx][ny] << '\n';
//
//			teat[map[nx][ny]] = true;
//			q.push({ nx, ny, nw, cnt + 1, teat });
//			//q.emplace( nx, ny, nw, teat, cnt + 1);
//		}
//	}
//}
//
//int main(int argc, char** argv)
//{
//	FIO;
//	int test_case;
//	int T;
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case) {
//		ans = -1;
//		memset(map, 0, sizeof(map));
//
//		cin >> n;
//		F(x, n) F(y, n) cin >> map[x][y];
//
//		F(x, n) F(y, n) {
//			if (y == 0 || y == n - 1 || x > n - 3) continue;
//			cout << "start : " << x << ", " << y << '\n';
//			bfs(x, y);
//		}
//
//		cout << "#" << test_case << " " << ans << '\n';
//	}
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}
///*
//// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
//// 20200606 1449
//#include <iostream>
//#include <set>
//#include <queue>
//#include <memory.h>
//using namespace std;
//#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
//#define MAX 21
//#define F(i, n) for(int i = 0 ; i < n ; ++i)
//
//struct P { int x, y, w; bool eat[101]; int cnt; };
//int dx[] = { 1, 1,-1,-1 }, dy[] = { 1,-1,-1,1 };
//int map[MAX][MAX];
//int n, ans;
//
//bool check(int x, int y) {
//	return !(x < 0 || y < 0 || x >= n || y >= n);
//}
//
//void bfs(int x, int y) {
//
//	queue<P> q;
//	bool eat[101]{};
//	eat[map[x][y]] = true;
//	q.emplace( x, y, 0, eat, 0 );
//
//	while (!q.empty()) {
//		int tx = q.front().x, ty = q.front().y, tw = q.front().w;
//		bool teat[101];
//		memcpy(teat, q.front().eat, sizeof(teat));
//
//		int cnt = q.front().cnt;
//
//		// 두개의 방향만 갈 수 있음
//		F(a, 2) {
//			int nw = tw + a;
//			if (nw == 4) continue;
//
//			int nx = tx + dx[nw], ny = ty + dy[nw];
//			if (!check(nx, ny) || nx < x) continue;
//
//			if (nx == x && ny == y) {
//				ans 
//		q.pop();= max(ans, cnt);
//				continue;
//			}
//
//			if (teat[map[nx][ny]]) continue;
//
//			// cout << "nx, ny : " << nx << ", " << ny << " << " <<  tst.size() << " : " << map[nx][ny] << '\n';
//
//			teat[map[nx][ny]] = true;
//			q.emplace( nx, ny, nw, teat, cnt + 1);
//
//		}
//	}
//}
//
//int main(int argc, char** argv)
//{
//	FIO;
//	int test_case;
//	int T;
//	cin >> T;
//
//	for (test_case = 1; test_case <= T; ++test_case) {
//		ans = -1;
//		memset(map, 0, sizeof(map));
//
//		cin >> n;
//		F(x, n) F(y, n) cin >> map[x][y];
//
//		F(x, n) F(y, n) {
//			if (y == 0 || y == n - 1 || x > n - 3) continue;
//			//cout << "start : " << x << ", " << y << '\n';
//			bfs(x, y);
//		}
//
//		cout << "#" << test_case << " " << ans << '\n';
//	}
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}
//
//*/
//
//
///*
//10
//4
//9 8 9 8
//4 6 9 4
//8 7 7 8
//4 5 3 5
//5
//8 2 9 6 6
//1 9 3 3 4
//8 2 3 3 6
//4 3 4 4 9
//7 4 6 3 5
//6
//1 8 9 6 3 9
//5 3 1 9 8 2
//6 9 3 4 1 2
//7 1 1 5 1 9
//1 9 6 8 7 3
//7 6 4 5 5 5
//7
//7 4 1 5 1 7 9
//9 4 6 1 4 6 8
//9 6 4 8 4 7 4
//3 2 6 2 4 2 8
//4 9 4 6 2 4 7
//1 7 6 8 9 5 8
//1 9 4 7 2 9 7
//8
//18 18 7 16 15 3 5 6
//3 6 8 3 15 13 15 2
//4 1 11 17 3 4 3 17
//16 2 18 10 2 3 11 12
//11 17 16 2 9 16 5 4
//17 7 6 16 16 11 15 8
//2 1 7 18 12 11 6 2
//13 12 12 15 9 11 12 18
//9
//12 3 10 8 11 12 5 3 11
//8 6 4 9 8 2 4 7 6
//6 10 12 8 3 8 11 3 3
//6 10 5 5 5 11 8 10 2
//5 13 3 7 5 6 5 12 6
//6 1 5 4 4 13 8 7 2
//12 7 13 3 5 1 11 7 3
//13 12 7 5 6 12 12 9 6
//1 12 13 13 11 3 4 10 9
//10
//18 8 21 24 8 4 20 15 14 23
//17 22 3 14 3 19 19 7 6 13
//2 26 10 10 10 7 18 14 15 17
//13 25 7 20 18 21 8 2 4 24
//4 3 1 5 15 3 15 12 22 23
//19 22 9 17 6 9 22 26 2 5
//12 13 19 13 6 2 12 19 24 8
//21 21 24 15 4 1 20 13 14 5
//6 10 17 13 7 4 22 16 9 7
//17 8 12 11 20 13 5 24 11 3
//11
//19 1 20 18 8 11 21 11 4 19 14
//14 17 6 10 19 3 5 9 18 20 7
//4 8 9 3 3 1 3 17 3 19 21
//20 19 13 21 20 17 5 21 15 3 10
//18 1 7 16 19 21 15 8 7 17 5
//21 1 3 11 14 4 15 10 14 15 17
//5 15 5 12 16 5 15 14 8 11 5
//14 18 2 19 19 8 5 7 11 11 1
//20 9 13 8 16 4 21 20 12 16 1
//9 11 7 18 5 19 5 18 13 18 20
//5 16 1 12 6 15 8 15 3 18 7
//14
//11 31 22 3 36 20 10 23 6 5 22 22 19 29
//9 7 13 9 31 15 7 1 13 33 11 24 7 36
//21 22 6 19 23 4 6 21 14 36 9 4 30 21
//17 2 30 13 26 36 2 13 32 27 36 5 28 16
//8 20 12 16 31 10 32 15 19 24 34 20 1 16
//17 18 22 3 10 2 30 26 27 29 10 16 24 12
//25 32 31 20 10 29 19 11 32 23 28 20 33 24
//9 13 19 4 6 27 24 5 16 2 8 34 2 7
//21 5 5 26 2 35 7 36 21 22 23 33 2 6
//16 21 15 21 12 11 13 28 3 3 14 23 16 4
//1 31 35 33 23 29 12 18 24 25 19 33 17 13
//29 6 30 19 33 14 35 14 6 23 27 16 12 24
//26 31 30 10 16 21 7 4 16 25 31 19 21 8
//12 5 2 4 4 27 29 2 18 20 19 26 32 31
//20
//11 34 7 49 59 88 79 12 63 38 13 27 9 70 97 92 86 95 84 18
//11 84 39 44 86 86 59 52 61 97 81 94 92 78 32 7 5 62 41 75
//15 61 71 27 3 4 79 51 95 99 73 27 75 31 4 7 15 51 50 16
//6 81 32 61 75 24 36 26 57 55 52 15 35 44 30 25 2 54 12 25
//42 4 66 1 23 44 1 7 63 27 82 70 40 45 4 3 12 35 11 85
//97 55 69 49 34 79 37 69 89 66 85 22 23 88 24 79 1 48 85 72
//4 67 23 3 27 18 37 61 7 68 88 80 35 21 42 88 38 10 81 84
//78 86 21 50 46 13 50 9 54 3 1 94 85 75 80 45 31 100 29 70
//9 59 7 48 81 82 43 68 90 37 26 41 84 31 58 42 4 96 86 20
//22 4 49 94 74 42 6 38 84 90 29 95 84 36 18 4 10 34 71 26
//46 43 7 88 18 21 96 57 3 72 52 83 50 53 56 51 19 50 57 6
//15 30 88 26 49 10 6 12 98 81 47 88 82 2 68 85 62 12 92 88
//100 31 5 15 76 84 39 10 52 61 28 12 50 22 35 85 1 83 2 76
//17 27 83 45 18 4 95 37 23 96 58 49 36 47 13 10 41 38 37 6
//22 92 59 68 51 15 65 88 18 69 40 49 7 11 78 14 95 94 45 27
//13 36 33 22 29 49 11 10 50 91 15 71 87 83 63 26 76 89 28 9
//98 9 96 58 72 79 28 9 63 67 85 16 40 66 46 47 17 85 16 99
//42 87 28 97 60 89 92 90 51 60 96 22 51 95 55 44 16 9 51 69
//27 45 53 43 45 52 12 90 86 91 47 39 84 9 21 77 69 56 5 69
//99 47 66 91 71 2 9 26 43 54 52 30 4 94 97 92 2 67 12 85
//
//#1 6
//#2 -1
//#3 4
//#4 4
//#5 8
//#6 6
//#7 14
//#8 12
//#9 18
//#10 30
//
//*/


