// 20201017 1500 - 1700
#include <cstdio>
#include <iostream>
#include <memory.h>
#include <vector>
#pragma warning (disable : 4996)
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 101
using namespace std;
enum WAYS { UP, RIGHT, DOWN, LEFT };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
// [블록번호][현재방향] >> 다음방향
int dblock[][4] = {
	  {-1, -1, -1, -1}
	, {DOWN, LEFT, RIGHT, UP }
	, {RIGHT, LEFT, UP, DOWN }
	, {LEFT, DOWN, UP, RIGHT }
	, {DOWN, UP, LEFT, RIGHT }
	, {DOWN, LEFT, UP, RIGHT }
};
struct BLOCK { int x, y, idx, d; };
int n, ans;
int map[MAX][MAX];
vector<BLOCK> wormhole;

bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= n);
}

BLOCK find_another_wormhole_idx(BLOCK block) {
	//cout << "CHECK HOLE : " << block.idx << " : " << block.x << ", " << block.y << '\n';
	for (BLOCK b : wormhole) {
		//cout << "HOLE : " << b.idx << " : " << b.x << ", " << b.y << '\n';
		if (block.idx == b.idx && (block.x != b.x || block.y != b.y)) {
			//cout << block.idx << " : " << b.x << ", " << b.y << '\n';
			return b;
		}
	}
}

void solve(int x, int y, int d) {
	int sum = 0;
	cout << " # START /// " << x << ", " << y << " : " << (WAYS)d << '\n';

	int nx = x + dx[d], ny = y + dy[d];

	while (1) {
		cout << nx << ", " << ny << " : " << (WAYS) d << '\n';
		/* 벽	: 반대 방향 */
		if (!check(nx, ny)) {
			sum++;
			d = (d + 2) % 4;
			nx += dx[d], ny += dy[d];
		}
		/* 시작점 */
		else if (nx == x && ny == y) {
			cout << "시작점\n";
			break;
		}
		/* 블랙홀 */
		else if (map[nx][ny] == -1) {
			cout << "블랙홀\n";
			break;
		}
		/* 빈칸 : 전진 */
		else if (map[nx][ny] == 0) {
			nx += dx[d], ny += dy[d];
		}
		/* 벽돌	: 회전 전진 */
		else if (1 <= map[nx][ny] && map[nx][ny] <= 5) {
			sum++;
			int block_num = map[nx][ny];
			d = dblock[block_num][d];
			nx += dx[d], ny += dy[d];
		}
		/* 웜홀	: 다른 웜홀 이동 */
		else if (6 <= map[nx][ny] && map[nx][ny] <= 10) {
			BLOCK b = find_another_wormhole_idx({ nx, ny, map[nx][ny], d });
			cout << "웜홀 : " << nx << ", " << ny << " >> " << b.x << ", " << b.y << '\n';
			nx = b.x + dx[d], ny = b.y + dy[d];
		}
	}

	if (ans < sum) ans = sum;
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
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case) {
		memset(map, 0, sizeof(map));
		wormhole.clear();
		ans = 0, n = 0;

		cin >> n;
		F(x, n) F(y, n) {
			cin >> map[x][y];
			if (6 <= map[x][y] && map[x][y] <= 10) {
				wormhole.push_back({x, y, map[x][y] });
			}
		}
		
		// 모든 빈공간 시작점
		F(x, n) F(y, n) if (map[x][y] == 0) {

			// 4방향 시작
			F(d, 4) solve(x, y, d);
		}

		cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*
1
5
0 6 7 6 7
5 5 5 5 5
5 5 5 5 5
5 5 5 5 5
5 5 5 5 5

>> 1
*/