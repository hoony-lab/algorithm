#include <iostream>
#include <deque>

#define MAX(a, b) a > b ? a : b
#define FIO std::ios_base::sync_with_stdio(false), std::cin.tie(NULL);
#define FOR(i, n, m) for(int i = m ; i < n ; ++i)

int n, d, k, coupon, sushi_belt[3000001], ans, eat[3001], sum;
std::deque<int> dq;
/*
연속된 초밥이면 할인
초밥의 종류가 쓰인 쿠폰
- 행사 한번 참여하면 초밥 하나 무료
- 만약 행사 초밥이 없으면, 새로 만들어서 제공
*/

int main() {
	FIO;

	std::cin >> n >> d >> k >> coupon;
	FOR(i, n, 0) std::cin >> sushi_belt[i];

	//FOR(i, n, n - k) {
	//	dq.push_front(sushi_belt[i]);
	//	if (!eat[sushi_belt[i]]) sum++;
	//	eat[sushi_belt[i]]++;
	//}

	//FOR(i, n, 0) {
	//	int dqfront = dq.front();
	//	eat[dqfront]--;
	//	dq.pop_front();
	//	if (!eat[dqfront]) sum--;

	//	dq.push_back(sushi_belt[i]);
	//	if (!eat[sushi_belt[i]]) sum++;
	//	eat[sushi_belt[i]]++;


	//	if (!eat[coupon])	ans = MAX(ans, sum + 1);
	//	else				ans = MAX(ans, sum);
	//}

	FOR(i, k, 0) 
		if (!eat[sushi_belt[i]]++)  sum++;
	
	FOR(i, n, 0) {
		if (!--eat[sushi_belt[i]]) sum--;
		if (!eat[sushi_belt[(i + k) % n]]++)  sum++;

		if (!eat[coupon])	ans = MAX(ans, sum + 1);
		else				ans = MAX(ans, sum);
	}

	std::cout << ans;
	return 0;
}

/*
8 50 4 7
2
7
9
7
9
7
30
7

*/
