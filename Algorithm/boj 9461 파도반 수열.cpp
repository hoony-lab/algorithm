#include <iostream>
int main() {
	int t;
	std::cin >> t;

	//길게길게...생각하기... dp....
	long long dp[110];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;

	for (int i = 6; i < 105; ++i) 
		dp[i] = dp[i - 1] + dp[i - 5];

	while (t--) {
		int n;
		std::cin >> n;
		std::cout << dp[n] << '\n';
	}

}