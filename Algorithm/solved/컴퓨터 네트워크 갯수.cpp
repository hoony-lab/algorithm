#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
	int answer = 1;

	vector<int> network[201];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			
			if (computers[i][j]) {
				network[i].push_back(j);
				network[j].push_back(i);
			}

		}
	}

	int visit[201] = { 0, };

	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;
		visit[i] = answer;
		cout << "visit : " << visit[i] << endl;
		int size = network[i].size();
		for (int j = 0; j < size; j++) {
			if (network[i][j]){
				visit[j] = answer;
			cout << "visit : " << visit[j] << endl;
			}
		}
		answer++;
	}

	cout << answer << endl;
	return answer;
}
int main() {
	//solution(3, { {1, 1, 0},{1, 1, 0},{0, 0, 1} });
	solution(3, { {1, 1, 0},{1, 1, 1},{0, 1, 1 }});


}