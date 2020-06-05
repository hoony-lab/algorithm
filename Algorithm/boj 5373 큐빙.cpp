// https://www.acmicpc.net/problem/5373
// 20200605 1736
#include <iostream>
#include <vector>
#include <string>

#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define F(i, n) for(int i = 0 ; i < n ; ++i)

/*
흰색은 w, 노란색은 y, 빨간색은 r, 오렌지색은 o, 초록색은 g, 파란색은 b.
*/

/*
U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면이다.
+인 경우에는 시계 방향 (그 면을 바라봤을 때가 기준),
-인 경우에는 반시계 방향이다.
*/
enum AA{
	U,
	D,
	F,
	B,
	L,
	R
};
int t, n;
std::string tmp;
std::vector<std::string> rotate;
char cube[3][3];
int main() {
	
	std::cin >> t;
	while (t--) {

		rotate.clear();
		
		std::cin >> n;
		F(i, n) std::cin >> tmp, rotate.push_back(tmp);


	}

	// U의 색상 출력 (3x3)
	std::cout << 
	return 0;
}