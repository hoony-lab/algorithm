#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	int RGB[1002][3]{};
	cin >> RGB[1][0] >> RGB[1][1] >> RGB[1][2];

	for (int i = 2; i <= n; ++i) {
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
		RGB[i][0] += min(RGB[i - 1][1], RGB[i - 1][2]);
		RGB[i][1] += min(RGB[i - 1][0], RGB[i - 1][2]);
		RGB[i][2] += min(RGB[i - 1][0], RGB[i - 1][1]);
	}

	cout << min(min(RGB[n][0], RGB[n][1]), RGB[n][2]);
	return 0;
}