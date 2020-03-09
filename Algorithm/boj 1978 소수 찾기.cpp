#include <iostream>
#define MAX 100000
int main() {

	int prime[MAX] = { 0, };
	for(int i = 2; i < MAX ; ++i)
		prime[i] = 1;

	for (int i = 2; i < MAX; ++i) {
		if (!prime[i]) continue;
		for (int j = i * 2; j < MAX; j += i)
		{
			prime[j] = 0;
		}
	}

	int n, tmp, ans = 0;
	std::cin >> n;
	for(int i = 0 ; i < n ; ++ i){
		std::cin >> tmp;
		if (prime[tmp]) ans++;
	}
	std::cout << ans;

}