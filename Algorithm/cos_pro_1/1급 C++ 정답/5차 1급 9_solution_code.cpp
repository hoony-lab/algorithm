#include <vector>
#include <queue>

using namespace std;

int solution(int number, int target) {
	int answer = 0;

	vector<int> visited(10001, 0);
	queue<int> q;
	q.push(number);
	visited[number] = 1;

	while(!q.empty()) {
		int x = q.front();
		q.pop();

		if(x == target)
			break;

		if(x+1 <= 10000 && visited[x+1] == 0) {
			visited[x+1] = visited[x]+1;
			q.push(x+1);
		}
		if(x-1 >= 0 && visited[x-1] == 0) {
			visited[x-1] = visited[x]+1;
			q.push(x-1);
		}
		if(2*x <= 10000 && visited[2*x] == 0) {
			visited[2*x] = visited[x]+1;
			q.push(2*x);
		}
	}

	answer = visited[target]-1;
	return answer;
}