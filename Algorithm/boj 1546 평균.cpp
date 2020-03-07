#include <iostream>
#define FOR(i,n) for(int i = 0 ; i < n ; ++i)
#define MAX(x,y) x > y ? x : y

int main() {

	float n, m, score[1001], max_score = 0, total_score = 0;
	std::cin >> n;

	FOR(i, n) {
		std::cin >> score[i];
		total_score += score[i];
		max_score = MAX(score[i], max_score);
	}
	
	std::cout << 100 * total_score / max_score / n;

	return 0;
}