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

void solve(int lvl, int rotate) {
	//cout << "====LVL : " << lvl << " :: SURFACE : " << dt[lvl][rotate] << "===\n";
	if (lvl == n) {
		ans = MAX(ans, sum);
		return;
	}

	F(new_rotate, 6) {
		// pass whats not having same surface  / dice[lvl][surface]
		//// ¾Æ·¡Ãþ À§ & À§Ãþ ¾Æ·¡
		if (dice[lvl][rotate] == dice[lvl + 1][dt[new_rotate][5]] || lvl + 1 == n) {


			int side_max = -1;
			for (int side = 1; side < 5; ++side) {
				side_max = MAX(side_max, dice[lvl][dt[rotate][side]]);
				//cout << "rotate : " << rotate << ", SIDE : " << dice[lvl][dt[rotate][side]] << '\n';
			}

			sum += side_max;
			solve(lvl + 1, new_rotate);
			sum -= side_max;
		}
	}
}

int main() {
	cin >> n; F(i, n) F(j, 6) cin >> dice[i][j];

	// check all surfaces
	// lvlÃþ & È¸Àü È½¼ö > °¡ÀåÅ«¸é
	F(i, 6) solve(0, i);
	
	cout << ans;
	return 0;
}
/*

5
2 3 1 6 5 4
3 1 2 4 6 5
5 6 4 1 3 2
1 3 6 2 4 5
4 1 6 5 2 3

*/