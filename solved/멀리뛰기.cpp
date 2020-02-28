#include <string>
#include <vector>
#include <iostream>
using namespace std;
long long answer = 0;

void dfs(int n, int num) {
	if (0 > n) {
		return;
	}
	else if (0 == n) {
		answer++;
		return;
	}

	for (int num = 1; num <= 2; ++num) {
		n -= num;
		dfs(n, num);
		n += num;
	}

}
int jumpCase(int n) {
	if (n == 1) return 1; else if (n == 2) return 2; else return (jumpCase(n - 1) + jumpCase(n - 2));
}
long long solution(int n) {
	//dfs(n, 0);
	//return answer;

	long long dp[10001] = { 0, };
		dp[0] = 1; dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
		}
	return dp[n] % 1234567;

	//return jumpCase(4);
}
/*
1 1
2 2
3 3
4 5
5 8
6 13
7 21
8 34
*/
int main() {

	cout << solution(8);



}