#include <iostream>
#define ll long long
ll map[2 ^ 15][2 ^ 15];
int main() {
	ll n, r, c, ans = 0, count = 0;
	std::cin >> n >> r >> c;

	
	map[0][0] = count++;
	map[0][1] = count++;
	map[1][0] = count++;
	map[1][1] = count++;

	map[0][2] = count++;
	map[0][3] = count++;
	map[1][2] = count++;
	map[1][3] = count++;

	map[2][0] = count++;
	map[2][1] = count++;

	std::cout << ans;
	return 0;
}

/*
2^N * 2^N			
1	2 2		4-1 3
2	4 4		16-1 15
3	8 8		64-1 63
4	1616	

2 3 1		11
3 7 7		63
*/