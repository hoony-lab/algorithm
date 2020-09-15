#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll n, m, play[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> play[i];

	if (n <= m) {
		cout << n;
		return 0;
	}

	ll l, r, t, min;
	l = t = 0;
	r = 2e12;

	while (l <= r) {
		ll mid = (l + r) >> 1;
		min = m;

		for (int i = 0; i < m; i++)
			min += mid / play[i];

		if (min >= n)
			t = mid, r = mid - 1;
		else
			l = mid + 1;
	}

	min = m;

	for (int i = 0; i < m; i++)
		min += (t - 1) / play[i];

	for (int i = 0; i <= m; i++) {
		if (t % play[i] == 0) min++;

		if (min == n) {
			cout << i + 1;
			return 0;
		}
	}

	return 0;
}
/*
1	2	3	4	5
1
1	2
1		3
1	2		4
1				5
1	2	3
1
1	2		4!!

1		3
1	2			5
1		3
1	2		4
*/