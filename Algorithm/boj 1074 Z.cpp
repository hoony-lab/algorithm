#include <iostream>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define ll long long
#define MAX (1<<15)+4
ll n, r, c, ans;

void Z(int y, int x, int size)
{
    if (y == r && x == c) {
        std::cout << ans << '\n';
        return;
    }

    // r,c가 현재 사분면에 존재한다면
    if (r < y + size && r >= y && c < x + size && c >= x) {
        // 1사분면 탐색
        Z(y, x, size / 2);
        // 2사분면 탐색
        Z(y, x + size / 2, size / 2);
        // 3사분면 탐색
        Z(y + size / 2, x, size / 2);
        // 4사분면 탐색
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else {
        ans += size * size;
    }
}

int main() {
	std::cin >> n >> r >> c;

	Z(0, 0, (1 << n));

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