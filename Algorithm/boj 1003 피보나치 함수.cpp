#include <iostream>
int ans[2][41];
int dp[41];

int fib(int n) {
	if (n == 0) {
		//ans[n]++;
		return 0;
	}
	else if (n == 1) {
		//ans[n]++;
		return 1;
	}
	else return fib(n - 2) + fib(n - 1);
}

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;

		// 1
		//fib(n);

		// 2
		//ans[0][0] = 1;
		//ans[1][0] = 0;

		//ans[0][1] = 0;
		//ans[1][1] = 1;

		//ans[0][2] = 1;
		//ans[1][2] = 1;

		//ans[0][3] = 1;
		//ans[1][3] = 2;

		//ans[0][4] = 2;
		//ans[1][4] = 3;

		//ans[0][5] = 3;
		//ans[1][5] = 5;

		//ans[0][6] = 5;
		//ans[1][6] = 8;

		//for (int i = 2; i <= n; ++i) {
		//	for(int a = 0 ; a < 2 ; ++ a)
		//		ans[a][i] = ans[a][i - 2] + ans[a][i - 1];
		//}

		//std::cout << ans[0][n] << " " << ans[1][n] << '\n';

		dp[0] = 0;
		dp[1] = 1;

		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		if (n == 0)	std::cout << 1 << " " << 0 << '\n';
		else		std::cout << dp[n - 1] << " " << dp[n] << '\n';
	}

}