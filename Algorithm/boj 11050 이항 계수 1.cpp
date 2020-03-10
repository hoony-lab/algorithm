#include <iostream>

/*
이항 계수 (binomial coefficient)
n개의 서로 다른 것들 중에서 k개를
선택하는 조합(combination)의 경우의 수

nCk = n! / (k! * (n-k)!)

팩토리얼 표현을 반복/재귀로 표현하는게 핵심
*/

int cache[100][100] = { 0, };
int fact[100];

long long func(int n, int k) {
	if (n == 0 || n == k) return 1;
	if (cache[n][k] != 0) return cache[n][k];

	cache[n][k] = func(n-1, k-1) + func(n-1,k);
	
	return cache[n][k];
}

void factorial(int n) {
	fact[0] = 1;

	for (int i = 1; i <= n; i++)
		fact[i] = fact[i - 1] * i;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);	std::cout.tie(NULL);

	int n, k, ans = 0;
	std::cin >> n >> k;

	factorial(n);

	std::cout << fact[n] / fact[k] / fact[n-k];
	
}