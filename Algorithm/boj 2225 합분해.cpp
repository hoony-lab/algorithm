#include <iostream>
#include <cstring>
#define ll long long
#define M 1000000000
ll n, k, dp[203][203];
int main() {
	std::cin >> n >> k;

	for (int i = 0; i <= n; ++i) dp[i][1] = 1;
	for (int i = 0; i <= k; ++i) dp[1][i] = i;

	if (k == 1) {
		std::cout << 1;
		return 1;
	}

	for (int i = 2; i <= n; ++i) {

		for (int j = 2; j <= k; j++) {

			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % M;

		}
	}
	/*
	dp[2][2] = dp[2][1] + dp[1][2];
	dp[2][1] = 1;
	dp[1][2] = 2;
	*/
	std::cout << dp[n][k];

	return 0;
}

/*
dp[0][0] = 0;
dp[0][1] = 1;
dp[0][2] = 1;
dp[0][3] = 1;

dp[1][3] = 3;


dp[0][1] = 1;
dp[1][1] = 1;
dp[2][1] = 1;
dp[3][1] = 1;

dp[3][2] = 4;



dp[0][2] = 1;
dp[1][2] = 2;
dp[2][2] = 3;
dp[3][2] = 4;	dp[3][3] = 10;
dp[4][2] = 5;

dp[4][3] = 15;

dp[3][3] = 10;
dp[4][2] = 5;



dp[1][1] = 1;
dp[1][2] = 2;
dp[1][3] = 3;
dp[1][4] = 4;

dp[2][2] = 3;
dp[2][3] = 6;
dp[2][4] = 10;
0 04
0 13
0 22
0 31
0 40

1 03
1 12
1 21
1 03

2 02
2 11
2 20

3 01
3 10

4 00
*/