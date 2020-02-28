// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> garden) {
	// 여기에 코드를 작성해주세요.
	int answer = 0;

	int dy[] = { 1,0,-1,0 };
	int dx[] = { 0,1,0,-1 };
	
	int visited[101][101] = { 0, };

	queue<pair<int, int>> q;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (garden[x][y]) {
				q.push(make_pair(x, y));
				visited[x][y] = 1;
			}
		}
	}

	
	while (!q.empty()) {

		int qsize = q.size();

		for (int i = 0; i < qsize; i++) {
			int tx = q.front().first;
			int ty = q.front().second;
			q.pop();
			
			for (int a = 0; a < 4; a++) {
				int nx = tx + dx[a];
				int ny = ty + dy[a];

				if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[nx][ny]) continue;

				q.push(make_pair(nx, ny));
				visited[nx][ny] += visited[tx][ty] + 1;
			}
			answer = max(answer, visited[tx][ty]);
		}
	}
    return answer - 1;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int n1 = 3;
    vector<vector<int>> garden1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int ret1 = solution(n1, garden1);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;
    
    int n2 = 2;
    vector<vector<int>> garden2 = {{1, 1}, {1, 1}};
    int ret2 = solution(n2, garden2);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;


}