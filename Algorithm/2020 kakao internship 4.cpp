#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define F(i, n) for(int i = 0 ; i < n ; ++i)

#define MAX 30
using namespace std;
using vvi = vector<vector<int>>;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0 ,-1 ,0 };
int n;

struct pos {
	int x, y, state, cost;
};
void print(int visit[][MAX]) {
	F(x, n) {
		F(y, n) {
			cout << visit[x][y] << "\t";
		}cout << '\n';
	}cout << "\n\n";
}

int bfs(vvi board) {
	int visit[MAX][MAX]{};
	F(x, n) F(y, n) visit[x][y] = 1e9;
	int min_cost = 1e9;
	queue<pos> q;
	q.push({ 0,0,-1,-500 });
	visit[0][0] = 0;

	while (!q.empty()) {
		int tx = q.front().x, ty = q.front().y, ts = q.front().state, tc = q.front().cost;
		q.pop();

		if (tx == n - 1 && ty == n - 1) {
			if (tc < min_cost)
				min_cost = tc;
			continue;
		}
		

		F(a, 4) {
			int nx = tx + dx[a], ny = ty + dy[a], dc = 100;


			if (nx < 0 || ny < 0 || nx >= n || ny >= n ||  board[nx][ny]) continue;

			if (ts != a /*&& (tx != 0 && ty != 0)*/) {
				dc += 500;
				//cout << "corner : " << tx << ", " << ty << ",, " << ts<< " ::: " << nx << ", " << ny << ",, " << a << '\n';
			}

			if (visit[nx][ny] < tc + dc) continue;

			//cout << "add : " << nx << ", " << ny << '\n';
			q.push({ nx, ny, a, tc + dc });
			visit[nx][ny] = tc + dc;
		}
	}
	//print(visit);
	return min_cost;
}
int solution(vector<vector<int>> board) {
	n = board.size();

    int answer = bfs(board);
    return answer;
}


int main() {

	//auto a = solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });			// 3, 7
	//auto b = solution({ "AA", "AB", "AC", "AA", "AC" });		// 1, 3
	//auto c = solution({ "XYZ", "XYZ", "XYZ" });					// 1, 1
	cout << solution({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}} ) << '\n';	// 900

	cout << '\n';


	cout << solution({{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}} ) << '\n';		// 3800

	cout << '\n';


	cout << solution({{0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 0}} ) << '\n';	// 2100

	cout << '\n';


	cout << solution({{0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1}, {0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0}} ) << '\n';	// 3200


	return 0;
}