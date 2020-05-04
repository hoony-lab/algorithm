#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <set>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define MAX 101
using namespace std;
using vvi = vector<vector<int>>;
int visit[MAX][MAX];
int n;
// LDRU
int d[][2] = { {0, -1}, { 1, 0},  {0 , 1}, {-1, 0} };
//int dy[] = { -1, 0, 1, 0 };

int dh1[][2] = { {1, 1}, {-1, 1}, {0, 0}, {0, 0 } };
int dh2[][2] = { {0, 0}, {0, 0}, {1, -1}, {-1, -1 } };
int dhr[][2] = { {1, 0}, {-1, 0}, {1, 1}, {-1, 1} };

int dv1[][2] = { {1, 1}, { 1,-1}, {0,  0}, { 0,  0 } };
int dv2[][2] = { {0, 0}, { 0, 0}, {-1, 1}, {-1, -1 } };
int dvr[][2] = { {0, 1}, {0, -1}, {1, 1}, {1, -1} };

struct pos {
	int x, y;
	//bool operator<(const pos& p) const { return x < p.x; }
};
struct Robot {
	pos p1, p2;
	bool operator<(const Robot& r) const {
		if (p1.y == r.p1.y)
			return p1.x < r.p1.x;
		return p1.y < r.p1.y;
	}
};
//auto cmp = [](const Robot r1, const Robot r2) { return r1.p1.x < r2.p1.x; };
//set < Robot, decltype(cmp) > robot_pos(cmp);

set<Robot> robot_pos;

void print() {
	F(x, n) {
		F(y, n) {
			cout << visit[x][y] << ' ';
		}cout << '\n';
	}cout << "\n\n";
}

bool chk(pos p, vvi board, int visit[][MAX]) {
	return !(p.x < 0 || p.y < 0 || p.x >= n || p.y >= n ||
		visit[p.x][p.y] > 40 || board[p.x][p.y]);
}

bool chk_rotate(pos p, vvi board) {
	return !(p.x < 0 || p.y < 0 || p.x >= n || p.y >= n ||
		board[p.x][p.y]);
}

int bfs(vvi board, int time) {

	queue<Robot> q;
	q.push({ { 0,0 }, { 0, 1 } });
	visit[0][0]++, visit[0][1]++;
	robot_pos.insert({ { 0,0 }, {0, 1} });

	while (!q.empty()) {
		cout << "TIME : " << time << " :: " << robot_pos.size() <<'\n';
		print();

		int qsize = q.size();
		F(i, qsize) {
			pos p1 = q.front().p1;
			pos p2 = q.front().p2;
			q.pop();

			if ((p2.x == n - 1 && p2.y == n - 1) ||
				(p1.x == n - 1 && p1.y == n - 1)) return time;

			F(a, 4) {
				pos np1 = { p1.x + d[a][0], p1.y + d[a][1] };
				pos np2 = { p2.x + d[a][0], p2.y + d[a][1] };
				if (!chk(np1, board, visit) || !chk(np2, board, visit) || robot_pos.count({ np1,np2 })) continue;

				q.push({ np1, np2 });
				visit[np1.x][np1.y]++;
				visit[np2.x][np2.y]++;
				robot_pos.insert({ np1,np2 });
			}


			F(a, 4) {
				pos np1, np2;
				// vertical
				if (abs(p2.x - p1.x) != 0) {
					if (p2.x < p1.x) swap(p1, p2);

					np1 = { p1.x + dv1[a][0], p1.y + dv1[a][1] };
					np2 = { p2.x + dv2[a][0], p2.y + dv2[a][1] };

					if (!chk(np1, board, visit) || !chk(np2, board, visit) || robot_pos.count({ np1,np2 })) continue;
					if (board[p1.x + dvr[a][0]][p1.y + dvr[a][1]]) continue;
				}
				// horizontal
				else {
					if (p2.y < p1.y) swap(p1, p2);

					np1 = { p1.x + dh1[a][0], p1.y + dh1[a][1] };
					np2 = { p2.x + dh2[a][0], p2.y + dh2[a][1] };

					if (!chk(np1, board, visit) || !chk(np2, board, visit) || robot_pos.count({ np1,np2 })) continue;
					if (board[p1.x + dhr[a][0]][p1.y + dhr[a][1]]) continue;

				}
				q.push({ np1, np2 });
				visit[np1.x][np1.y]++;
				visit[np2.x][np2.y]++;
				robot_pos.insert({ np1,np2 });
			}
		}

		time++;
	}
}

int solution(vector<vector<int>> board) {
	n = board.size();

	return bfs(board, 0);
}

int main() {
	vvi board = {
		{0, 0, 0, 1, 1},
		{0, 0, 0, 1, 0},
		{0, 1, 0, 1, 1},
		{1, 1, 0, 0, 1},
		{0, 0, 0, 0, 0} };
	cout << solution(board);        // 7

	return 0;
}