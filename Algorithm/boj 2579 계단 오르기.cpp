#include <iostream>

int main() {
	int floor[301] = { 0, }, dp[301] = { 0, };
	int t, n;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> n;
		floor[i] = n;
	}

	dp[0] = floor[0];
	dp[1] = floor[1] > floor[0] + floor[1] ?
		floor[1] : floor[0] + floor[1];
	dp[2] = floor[2] + dp[0] > floor[2] + dp[1]?
		dp[1] : floor[1] + floor[2];

	for (int i = 3; i < t; i++) {
		dp[i] = floor[i] + dp[i - 2] > floor[i] + dp[i - 1] ?
			floor[i] + dp[i - 2] : floor[i] + dp[i - 1];
	}
	std::cout << dp[t - 1];
}