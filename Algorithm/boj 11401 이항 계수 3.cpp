#include <iostream>
#define FOR(i, x, n) for(int i = x; i > x-n ; -- i)
using namespace std;

int main(){
	long long answer = 1;
	int n, k;
	cin >> n >> k;

	FOR(i, n, k)
		answer *= i;

	FOR(i, k, 1)
		answer /= i;

	cout << answer % 1000000007;

	return 0;
}