#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int min_ans = 1e10, max_ans = -1e10;
vector<int> num, op;

// + - * /
int cal() {
	int res = num[0];
	for (int i = 1; i < num.size(); i++) {
		switch (op[i - 1]) {
			case 0:	res += num[i];	break;
			case 1:	res -= num[i];	break;
			case 2: res *= num[i];	break;
			case 3: res /= num[i];	break;
			default:				break;
		}
	}
	return res;
}

int main() {
	FIO;

	int t, tmp;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> tmp;
		num.push_back(tmp);
	}
	for (int a = 0; a < 4; a++) {
		cin >> tmp;
		for (int i = 0; i < tmp; i++) {
			op.push_back(a);
		}
	}

	do {
		//for (int i : op) cout << i << ", "; cout << '\n';

		max_ans = max(max_ans, cal());
		min_ans = min(min_ans, cal());
	} while (next_permutation(op.begin(), op.end()));

	cout << max_ans << '\n' << min_ans << '\n';

	return 0;
}