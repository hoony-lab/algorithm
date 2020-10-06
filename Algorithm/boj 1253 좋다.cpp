#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, num[2001], ans = 0; cin >> n;
	unordered_map<int, pair<int, int>> m;

	for (int i = 0; i < n; ++i) {
		cin >> num[i];
		m[num[i]] = { 0, i };
	}
	 
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int sum = num[i] + num[j];

			// 합숫자가 원래숫자에 있으면
			if (m.count(sum)) {

				if (m[sum].second == i || m[sum].second == j) continue;

				m[sum].first++;
			}

		}
	}

	for (int i = 0; i < n; ++i)
		if (m[num[i]].first) ans++;
	
	cout << ans;
	return 0;
}
/*
15
1 2 3 4 5 6 7 8 9 0 10 10 0 0 0
13

3
0 3 3
2

3 0 1 2 ==> 0 
3 0 1 1 ==> 2 
3 0 1 -1 ==> 1 
4 0 1 1 2 ==> 3 
5 0 0 0 1 1 ==> 5 
5 0 0 0 1 2 ==> 3

출처: https://sdev.tistory.com/496 [잡동사니 개발자의 블로그]
*/