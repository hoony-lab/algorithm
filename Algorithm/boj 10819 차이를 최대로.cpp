#include <iostream>
#include <algorithm>
using namespace std;
int n, num[10], ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> num[i];

	sort(num, num + n);

	do {
		int sum = 0;
		for (int i = 1; i < n; ++i)
			sum += abs(num[i] - num[i - 1]);

		ans = max(ans, sum);

		//for (int i = 0; i < n; ++i) cout << num[i] << " "; cout << " : " << ans << "\n";

	} while (next_permutation(num, num + n));

	cout << ans;
	return 0;
}