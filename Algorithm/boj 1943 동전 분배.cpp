#include <iostream>
#include <vector>
using namespace std;
struct money {
	int p, c;
};

int main() {
	for (int t = 0; t < 3; ++t) {
		int n, tp, tc, sum = 0;
		vector<money> v;

		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> tp >> tc;
			v.push_back({ tp, tc });
			sum += tp * tc;
		}

		if (sum % 2 == 1) {
			cout << 0 << '\n';
			continue;
		}


	}
	return 0;
}