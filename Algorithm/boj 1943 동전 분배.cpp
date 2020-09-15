#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct money {
	int p, c;
};

int main() {
	for (int t = 0; t < 3; ++t) {
		int n, tp, tc, total = 0, sum[2]{};
		vector<money> v;

		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> tp >> tc;
			v.push_back({ tp, tc });
			total += tp * tc;
		}

		if (total % 2 == 1) {
			cout << 0 << '\n';
			continue;
		}

		sort(v.begin(), v.end(), [](const money& v1, const money& v2) {
			return v1.p > v2.p;
		});



		int dp[100000]{};
		for (int i = 1; i <= total; i++) dp[i] = 1e9;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= total; j++) {
				if (dp[j] == 1e9) continue;

				if ((dp[j] < v[i].c) && (j + v[i].p <= total)) {
					if (dp[j + v[i].p] > dp[j] + 1)
						dp[j + v[i].p] = dp[j] + 1;
				}
				dp[j] = 0;
			}
		}
		if (dp[total / 2] != 1e9)	cout << 1 << '\n';
		else						cout << 0 << '\n';

		//for (int i = 0; i < v.size(); i++) {
		//	for (int cc = 0; cc < v[i].c; cc++) {
		//		if (sum[0] < sum[1])	sum[0] += v[i].p;
		//		else					sum[1] += v[i].p;
		//	}
		//}
		//if (sum[0] == sum[1])	cout << 1 << '\n';
		//else					cout << 0 << '\n';
	}
	return 0;
}