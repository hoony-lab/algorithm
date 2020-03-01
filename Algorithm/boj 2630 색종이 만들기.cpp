#include <iostream>
#include <string.h>
using namespace std;

int n, white_count = 0, blue_count = 0;
int map[129][129];

void div_conq(int xx, int yy, int len) {

	int tmp_cnt = 0;
	for (int x = xx; x < xx + len; x++)
		for (int y = yy; y < yy + len; y++)
			if (map[x][y]) tmp_cnt++;

	if (!tmp_cnt) white_count++;
	else if (tmp_cnt == len * len) blue_count++;
	else {
		div_conq(xx, yy, len / 2);
		div_conq(xx, yy + len / 2, len / 2);
		div_conq(xx + len / 2, yy, len / 2);
		div_conq(xx + len / 2, yy + len / 2, len / 2);
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);		cout.tie(NULL);

	memset(map, 0, sizeof(map));
	
	cin >> n;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			cin >> map[x][y];
	
	div_conq(0, 0, n);
	
	cout << white_count << '\n' << blue_count;

	return 0;
}