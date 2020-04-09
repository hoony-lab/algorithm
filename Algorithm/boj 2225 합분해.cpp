#include <iostream>
#define ll long long
#define M 1000000000
ll n, k, dp[205][205];
int main() {
	std::cin >> n >> k;

	//for (int i = 0; i <= n; ++i) dp[i][0] = 0, dp[i][1] = 1, dp[i][2] = i + 1;
	//for (int i = 1; i <= k; ++i) dp[0][i] = 1, dp[1][i] = i;
	for (int i = 0; i <= k; ++i) dp[0][i] = 1;

	for (int N = 1; N <= n; N++) {

		for (int K = 1; K <= k; K++) {

			dp[N][K] += dp[N][K - 1] % M;
			dp[N][K] += dp[N - 1][K] % M;
			dp[N][K] %= M;

		}
	}

	std::cout << dp[n][k];
	return 0;
}

/*
nk
	0	1	2	3	4	5	6	7	8	9
0		1	1	1	1	1	1	1	1	1
1		1	2	3	4	5	6	7	8	9
2		1	3	6	10
3		1	4	10
4		1	5	15
5		1	6
6		1	7
7		1	8
8		1	9
9		1	10

dp[n][k] = dp[n][k-1] + dp[n-1][k-1] + ... + dp[1][k-1]
*/