#include <iostream>
#include <memory.h>
#define MIN(x,y) x>y?x:y;
long long dp[50001];

int main() {
	long long n;
	std::cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;
	//dp[2] = 1;
	//dp[3] = 1;
	//dp[4] = 2;
	//dp[5] = 2;	//4 + 1 ,1 1 1 1 1

	for (int i = 2; i <= n; i++) {
		dp[i] = 100;
		for (int j = 1; j*j <= i; j++)
		{
			dp[i] = MIN(dp[i], dp[i - j * j] + 1);
		}
	}
	std::cout << dp[n];
	
	return 0; 
}


