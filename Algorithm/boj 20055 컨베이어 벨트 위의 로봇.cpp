#include <iostream>
#include <queue>
using namespace std;
#define F(i,n) for(int i = 0 ; i < n ; ++i)
int n, k, a, belt[1001], robot[1001], result, zero_durability_cnt;


void rotate() {
	for (int i = n * 2 - 1; i > 0; --i) swap(belt[i], belt[i - 1]);
}
void init() {
	cin >> n >> k; F(i, n * 2) cin >> belt[i];
}
void solve() {
	// 벨트가 한 칸 회전한다.
	rotate();
	// 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
	for (int i = n * 2 - 1; i >= 0; --i)
		if (robot[i] && belt[i]) {
			swap(robot[i], robot[(i + 1) % (n * 2)]);
			belt[i]--;
		}

	// 올라가는 위치에 로봇이 없다면 로봇을 하나 올린다.
	if (!robot[0] && belt[0]) {
		robot[0] = true;
		belt[0]--;
	}

	if (robot[n] && belt[0]) {
		robot[n] = false;
		belt[n]--;
	}

}
int main() {

	init();
	while (1) {
		solve();

		// 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
		zero_durability_cnt = 0;
		F(i, 2 * n) if (!belt[i]) zero_durability_cnt++;
		if (zero_durability_cnt >= k) {
			cout << result;
			return 0;
		}
	}
}

/*
3 2
1 2 1
2 1 2

1.
2 1 2
1 2 1

2.
3.
1 1 2	1 0 0
1 2 1	0 0 0


1.
1 1 1
2 1 2

2.
0 1 1	0 1 0
2 1 2	0 0 0

3.


1.
2 0 1
1 2 1

2.
3.



1.
1 2 0
2 1 1

2.

*/