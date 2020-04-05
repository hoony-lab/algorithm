#include <iostream>
#include <cstring>
#define ll long long
/*
1부터 m까지 n개
이전의 고른 수보다 적어도 2배
1 2 4 8 16
*/
int main() {
	ll t, n, m, ans = 0, dp[11][2001];	//[n][m]
	std::cin >> t;
	
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= 2000; ++i) dp[1][i] = i;

	for (int i = 2; i <= 10; i++) {
		for (int j = 1; j <= 2000; j++) {

			dp[i][j] += dp[i][j - 1] + dp[i - 1][j / 2];

		}
	}

	while (t--) {
		std::cin >> n >> m;
		std::cout << dp[n][m] << '\n';
	}

	return 0;
}
/*
2승에 관계가 있어보인다...

nm
	1	2	3	4	5	6	7	8	9	10	... 2000
1	1	2	3	4	5	6	7	8	9	10
2		1	2	4	6	9	12	16	20	25	
3				1	2	4	6	10	14	18
4								1	2	4
.
.
.
10
*/