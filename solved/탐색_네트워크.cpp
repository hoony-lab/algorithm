#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool visited[201];

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	//
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		answer++;
		queue<int> q;
		q.push(i);

		while (!q.empty()) {
			int tx = q.front();
			q.pop();

			for (int j = 0; j < n; j++) {
				if (tx == j || !computers[tx][j] || visited[j]) continue;
				q.push(j);
				visited[j] = true;
				//answer++;
			}
		}

	}

	return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/43162