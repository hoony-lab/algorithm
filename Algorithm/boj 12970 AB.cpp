#include <iostream>
#include <vector>
#define MIN(a, b) a < b ? a : b
using namespace std;

//문자열 S의 길이는 N이고, 'A', 'B'로 이루어져 있다.
//문자열 S에는 0 ≤ i < j < N 이면서
// s[i] == 'A' && s[j] == 'B'를 만족하는(i, j) 쌍이 K개가 있다.
int main() {
	int n, k;
	cin >> n >> k;

	// a + b == n , a * b >= k
	for (int a = 0; a <= n; a++) {
		int b = n - a;

		if (a * b < k) continue;

		vector<int> va(b + 1);
		for (int i = 0; i < a; i++) {
			int after = MIN(b, k);

			va[after] += 1;
			k -= after;
		}

		for (int i = b; i >= 0; i--) {
			for (int j = 0; j < va[i]; j++)
				cout << 'A';
			if (i > 0)
				cout << 'B';
		}
		return 0;
	}
	cout << -1;
	return 0;
}
