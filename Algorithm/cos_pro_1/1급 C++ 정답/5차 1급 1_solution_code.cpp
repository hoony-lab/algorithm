#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	vector<int> steps(n+1) = {1, 2, 4};
	for(int i = 4; i <= n; i++)
		steps[i] = steps[i-1] + steps[i-2] + steps[i-3];
	answer = steps[n];

	return answer;
}