#include <iostream>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX(a, b) a > b ? a : b
using namespace std;

int dt[][6] = {
	{0,1,2,3,4,5},
	{1,5,2,0,4,3},
	{2,1,5,3,0,4},
	{3,0,2,5,4,1},
	{4,1,0,3,5,2},
	{5,1,4,3,2,0}
};
int n, dice[10001][6], ans, sum;

void solve(int lvl, int surface) {
	cout << "LVL : " << lvl << " :: SURFACE : " << surface << '\n';
	if (lvl == n) {
		ans = MAX(ans, sum);
		cout << "ANS : " << ans << "\n\n";
		return;
	}

	F(top, 6) {
		// pass whats not having same surface  / dice[lvl][surface]
		if (surface != dice[lvl+1][dt[top][5]]) continue;
		cout << surface << ":" << dice[lvl + 1][dt[top][5]] << " > " << dice[lvl + 1][dt[top][0]] << '\n';

		int tmp = 0;
		F(side, 5) {
			// pass Top & Bottom
			if (!side) continue;

			// max side num
			tmp = MAX(tmp, dice[lvl][dt[top][side]]);
			cout << "TOP : " << top << ", SIDE : " << side << ", TMP : " << tmp << '\n';
		}
		sum += tmp;
		solve(lvl + 1, dice[lvl][top]);
		sum -= tmp;
	}
}

int main() {
	cin >> n; F(i, n) F(j, 6) cin >> dice[i][j];

	// check all surfaces
	F(i, 6) solve(0, dice[0][i]);
	
	cout << ans;
	return 0;
}