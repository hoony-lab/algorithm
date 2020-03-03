#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string answer;
int n;
int map[65][65];


void div_conq(int xx, int yy, int len) {

	cout << "checking " << xx << ", " << yy << ", " << len << '\n';
	//int tmp_zero = 0, tmp_one = 0;
	bool flag = true;
	for (int x = xx; (x < xx + len) && flag; x++) {
		for (int y = yy; (y < yy + len) && flag; y++) {
			//if (map[x][y]) tmp_one++;
			//else tmp_zero++;
			if (map[x][y] != map[xx][yy]) flag = false;
		}
	}

	//if (tmp_one == len * len) {
	//	answer.append("1");
	//	cout << 1 << " append\n";
	//}
	//else if (tmp_zero == len * len) {
	//	answer.append("0");
	//	cout << 0 << " append\n";
	//}

	if (flag) {
		answer.append(to_string(map[xx][yy]));
	}
	else {

		answer.append("(");
		div_conq(xx, yy, len / 2);
		div_conq(xx, yy + len / 2, len / 2);
		div_conq(xx + len / 2, yy, len / 2);
		div_conq(xx + len / 2, yy + len / 2, len / 2);
		answer.append(")");
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);		cout.tie(NULL);

	cin >> n;
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			cin >> map[x][y];
		}
	}

	div_conq(0, 0, n);

	cout << answer;


	return 0;
}