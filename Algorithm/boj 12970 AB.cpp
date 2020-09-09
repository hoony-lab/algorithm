#include <iostream>
#include <string>
using namespace std;

//문자열 S의 길이는 N이고, 'A', 'B'로 이루어져 있다.
//문자열 S에는 0 ≤ i < j < N 이면서
// s[i] == 'A' && s[j] == 'B'를 만족하는(i, j) 쌍이 K개가 있다.
int main() {
	string ans;
	int n, k;
	cin >> n >> k;


	if (k > (n/2) * (n/2))
		cout << "-1";
	else if (k == 0) {
		cout << "B";
		for (int i = 0; i < n - 1; i++)
			cout << "A";
	}
	else cout << ans;
		return 0;
}