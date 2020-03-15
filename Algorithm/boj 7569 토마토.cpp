#include <iostream>
#include <queue>
#include <tuple>
#define FOR(i,n,m) for(int i = m ; i < n ; ++i)

int dx[] = { 0,1,0,-1,0,0 };
int dy[] = { 1,0,-1,0,0,0 };
int dl[] = { 0,0,0,0,1,-1 };
int map[101][101][101], visited[101][101][101];

int main() {
	//m은 상자 가로칸, n은 상자 세로칸
	int m, n, h;
	std::cin >> m >> n >> h;

	FOR(l, h, 0)	FOR(x, n, 0) FOR(y, m, 0)	std::cin >> map[l][x][y];

	bool is_tomato = false, is_all_mature_tomato = true;
	int time = 0;
	while (1) {

		//완료 검사
		FOR(l, h, 0) {
			FOR(x, n, 0) {
				FOR(y, m, 0) {
					if (map[l][x][y] == 0) {
						is_all_mature_tomato = false; break;
					}
					if (is_all_mature_tomato && map[h - 1][x - 1][y - 1] != 0) {
						if (!time) std::cout << 0;
						else std::cout << time;
						return 0;
					}
				}
				if (!is_all_mature_tomato) break;
			}
			if (!is_all_mature_tomato) break;
		}


		std::cout << "lets go\n";
		//순회	
		time++;
		FOR(l, h, 0)	FOR(x, n, 0)	FOR(y, m, 0) {
			if (map[l][x][y] != 1) continue;
			std::queue<std::tuple<int, int, int>> q;
			q.push(std::make_tuple(l, x, y));
			visited[l][x][y] = 1;
			std::cout << l << ", " << x << ", " << y << '\n';

			while (!q.empty()) {
				int tl = std::get<0>(q.front());
				int tx = std::get<1>(q.front());
				int ty = std::get<2>(q.front());
				q.pop();

				FOR(i, 6, 0) {
					int nl = tl + dl[i];
					int nx = tx + dx[i];
					int ny = ty + dy[i];

					if (nl < 0 || nx < 0 || ny < 0 || nl >= h || nx >= x || ny >= y) continue;
					if (map[nl][nx][ny] == -1 || visited[nl][nx][ny]) continue;
					
					std::cout << nl << ", " << nx << ", " << ny << '\n';
					q.push(std::make_tuple(nl, nx, ny));
					visited[nl][nx][ny] = 1;
					map[nl][nx][ny] = 1;
					is_tomato = true;
				}
			}
		}
		if (!is_tomato) {
			std::cout << -1; return 0;
		}
	}

}




//int row, col, box[101][101] = { 2, }, go = 1, ans = 0;
//vector<pair<int, int>> stack;
//cin >> row >> col;
//for (int i = 1; i <= col; i++) {
//	for (int j = 1; j <= row; j++) {
//		cin >> box[i][j];
//	}
//}
//
//for (int i = 1; i <= col; i++) {
//	for (int j = 1; j <= row; j++) {
//
//		if (box[i][j] == 1) {
//			stack.push_back(make_pair(i, j));
//			ans++;
//			cout << i << ", " << j << '\t' << endl;
//			while (!stack.empty())
//			{
//
//				i = stack.at(stack.size() - 1).first;
//				j = stack.at(stack.size() - 1).second;
//
//				stack.pop_back();
//
//
//				if (i > 1) {
//					if (box[i - 1][j] == 0) {
//						box[i - 1][j] = 1;
//						stack.push_back(make_pair(i - 1, j));
//						go = 1;
//						cout << i - 1 << ", " << j << '\t';
//					}
//				}
//				if (i + 1 <= col) {
//					if (box[i + 1][j] == 0) {
//						box[i + 1][j] = 1;
//						stack.push_back(make_pair(i + 1, j));
//						go = 1;
//						cout << i + 1 << ", " << j << '\t';
//					}
//				}
//				if (j + 1 <= row) {
//					if (box[i][j + 1] == 0) {
//						box[i][j + 1] = 1;
//						stack.push_back(make_pair(i, j + 1));
//						go = 1;
//						cout << i << ", " << j + 1 << '\t';
//					}
//				}
//				if (j > 1) {
//					if (box[i][j - 1] == 0) {
//						box[i][j - 1] = 1;
//						stack.push_back(make_pair(i, j - 1));
//						go = 1;
//						cout << i << ", " << j - 1 << '\t';
//					}
//				}
//				cout << "next stack" << endl;
//			}
//		}
//	}
//}
//
//cout << endl;
//for (int i = 1; i <= col; i++) {
//	for (int j = 1; j <= row; j++) {
//		cout << box[i][j];
//	}
//	cout << endl;
//}
//cout << endl;
//for (int i = 1; i <= col; i++) {
//	for (int j = 1; j <= row; j++) {
//		if (box[i][j] == 0)
//			ans = -1;
//	}
//}
//cout << ans;
