#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &parent, int u) {
	if(u == parent[u])
		return u;

	parent[u] = @@@;
	return parent[u];
}

bool merge(vector<int> &parent, int u, int v) {
	u = find(parent, u);
	v = find(parent, v);

	if(u == v)
		return true;

	@@@;
	return false;
}

int solution(int n, vector<vector<int>> connections) {
	int answer = 0;

	vector<int> parent(n+1);
	for(int i = 1; i <= n; i++)
		@@@;

	for(int i = 0; i < connections.size(); i++)
		if(merge(parent, connections[i][0], connections[i][1])) {
			answer = i + 1;
			break;
		}

	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int n = 3;
	vector<vector<int>> connections = {{1, 2}, {1, 3}, {2, 3}};
	int ret = solution(n, connections);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret << " 입니다."<< endl;
}