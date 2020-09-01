#include <iostream>
#include <vector>
#include <queue>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
using namespace std;

int dt[][6] = {
	{0,1,2,3,4,5},
	{1,5,2,0,4,3},
	{2,1,5,3,0,4},
	{3,0,2,5,4,1},
	{4,1,0,3,5,2},
	{5,1,4,3,2,0}
};
int n, dice[10001][6], ans;

void solve(int cnt, int dice) {
	if (cnt == n) {
					
	}
}

int main() {
	cin >> n; F(i, n) F(j, 6) cin >> dice[i][j];

	
	F(i, 6) solve(0, dice[0][i]);
	
	F(i, 5) { if (!i) continue;
		
	}

	return 0;
}