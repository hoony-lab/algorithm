#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> enemies, vector<int> armies) {
	int answer = 0;

	sort(enemies.begin(), enemies.end());
	sort(armies.begin(), armies.end());
	int i = 0, j = 0;
	while(i < enemies.size() && j < armies.size()) {
		if(enemies[i] <= armies[j]) {
			answer++;
			i++;
			j++;
		} else {
			j++;
		}
	}

	return answer;
}