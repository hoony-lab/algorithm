#include <iostream>

using namespace std;
int a, b, c;

int div_conq(int a, int b) {
	if (b == 0) return 1;

	int tmp = div_conq(a, b / 2);
	int result = (1LL * tmp * tmp) % c;

	if (b % 2) result = 1LL * result * a % c;

	return result;
}

int main() {

	cin >> a >> b >> c;
	
	cout << div_conq(a, b);

	return 0;
}
/*
11 > 5 5 1
5 > 2 2 1
2 > 1 1
*/

// https://velog.io/@litien/BOJ-1629-%EA%B3%B1%EC%85%88