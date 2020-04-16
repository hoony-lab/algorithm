#include <iostream>
#include <cstring>
#include <algorithm>
#define FIO std::ios_base::sync_with_stdio(false), std::cin.tie(NULL)
#define FOR(i,a,b) for(int i = a; i < b; ++i)

int n, guilty[17], g_index[27][27], eunjin;
int is_dead[27], ans;

int most_guilty(int guilty[]) {
	int max = 0, res = 0;
	FOR(i, 0, n) {
		if (is_dead[i] || eunjin == i) continue;
		if (max < guilty[i]) max = guilty[i], res = i;
	}
	return res;
}

void dfs(int guilty[], int g_index[][27], int is_dead[], int turn, int ppl) {
	int guilty_c[27], g_index_c[27][27];

	if (ppl == 1) {
		if(ans < turn) ans = turn;
		return;
	}

	// day
	// kill most guilty person
	if (ppl & 1) {
		int morning_dead = most_guilty(guilty);

		is_dead[morning_dead] = true;
		dfs(guilty_c, g_index_c, is_dead, turn, ppl - 1);
		is_dead[morning_dead] = false;
	}

	// night
	// kill random person (brute-force)
	else {
		FOR(i, 0, n) {
			if (is_dead[i] || eunjin == i) continue;

			memcpy(guilty_c, guilty, sizeof(guilty));
			memcpy(g_index_c, g_index, sizeof(g_index));
			
			FOR(j, 0, n) 
				guilty_c[j] += g_index_c[i][j];
			
			is_dead[i] = true;
			dfs(guilty_c, g_index_c, is_dead, turn + 1, ppl - 1);
			is_dead[i] = false;
		}
	}
}

int main() {
	FIO;

	std::cin >> n;
	FOR(i, 0, n) std::cin >> guilty[i];
	FOR(x, 0, n) FOR(y, 0, n) std::cin >> g_index[x][y];
	std::cin >> eunjin;
	
	dfs(guilty, g_index, is_dead, 0, n);

	std::cout << ans;

	return 0;
}
/*
4
500 500 500 500
1 4 3 -2
-2 1 4 3
3 -2 1 4
4 3 -2 1
1

2

*/