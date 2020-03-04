#include <iostream>

using namespace std;

#define MAXNUM 2188
int n;
int map[MAXNUM][MAXNUM];
int answer[3] = { 0, };

void div_conq(int xx, int yy, int len) {

	int div_len = len / 3;

	bool flag = true;
	for (int x = xx; x < (xx + len) && flag; x++)
		for(int y = yy; y < (yy + len) && flag; y++)
			if (map[xx][yy] != map[x][y]) flag = false;
		
	if (flag) {
		if (map[xx][yy] == 1) answer[2]++;
		else if (map[xx][yy] == 0) answer[1]++;
		else if (map[xx][yy] == -1) answer[0]++;
	}
	else {
		div_conq(xx, yy, div_len);
		div_conq(xx, yy + div_len, div_len);
		div_conq(xx, yy + div_len * 2, div_len);
		div_conq(xx + div_len, yy, div_len);
		div_conq(xx + div_len, yy + div_len, div_len);
		div_conq(xx + div_len, yy + div_len * 2, div_len);
		div_conq(xx + div_len * 2, yy, div_len);
		div_conq(xx + div_len * 2, yy + div_len, div_len);
		div_conq(xx + div_len * 2, yy + div_len * 2, div_len);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);		cout.tie(NULL);

	cin >> n;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			cin >> map[x][y];

	div_conq(0, 0, n);

	for (int i = 0; i < 3; i++)
		cout << answer[i] << '\n';


	return 0;
}