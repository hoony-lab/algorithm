//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//#include <memory.h>
//#include <algorithm>
//using namespace std;
//
//// 4 way checking
//int dy[] = { -1,1,1,-1 };
//int dx[] = { 1,1,-1,-1 };
//int map[1001][1001];
//
//// board[y][x]
//int solution(vector<string> board) {
//	int answer = 0, count=0, minsize;
//	char word;
//
//	int size = board.size();
//	for (int y = 1; y < size - 1; ++y) {
//		for (int x = 1; x < size - 1; ++x) {
//			cout << "POINT " << y << ", " << x << endl;
//
//			queue<pair<int, int>> q;
//			minsize = 1e9;
//
//			for (int a = 0; a < 4; a++) {
//				count = 0;
//				int ny = y;
//				int nx = x;
//				q.push({ ny,nx });
//
//				while (!q.empty()) {
//					ny = q.front().first + dy[a];
//					nx = q.front().second + dx[a];
//					q.pop();
//
//					if (ny >= size || nx >= size || ny < 0 || nx < 0 || board[ny][nx] != board[y][x] ) continue;
//
//					cout << "visiting " << ny << ", " << nx << '\n'; 
//
//					q.push({ ny,nx });
//					count++;
//				}
//				minsize = min(minsize, count);
//				//if (count > answer) break;
//			}
//			answer = max(answer, minsize);
//
//			cout << "\n MINSIZE = " << minsize << endl << endl;
//		}
//	}
//  if(answer == 0) return 0;
//	return answer * 2 + 1;
//}
//
//int main() {
//
//	cout << solution({ "ABCBA", "DABAG", "EBABH", "FAJAI", "AKLMA" }) << '\n';
//
//	cout << solution({ "ABCBA", "DABAG", "ENABH", "FAJAI", "AKLMO" }) << endl;
//
//
//}


#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

// 4 way checking
int dy[] = { -1,1,1,-1 };
int dx[] = { 1,1,-1,-1 };
int map[1001][1001];

// board[y][x]
int solution(vector<string> board) {
	int answer = 0, count=0, minsize;
	char word;

	int size = board.size();
	for (int y = 1; y < size - 1; ++y) {
		for (int x = 1; x < size - 1; ++x) {
			cout << "POINT " << y << ", " << x << endl;

			queue<pair<int, int>> q;
			minsize = 1e9;
			q.push({ y,x });
			count = 1;
			bool done = false;

			while (!q.empty()) {
				int ty = q.front().first;
				int tx = q.front().second;
				q.pop();

				for (int a = 0; a < 4; a++) {
					int ny = ty + dy[a] * count;
					int nx = tx + dx[a] * count;

					if (ny >= size || nx >= size || ny < 0 || nx < 0 || board[ny][nx] != board[y][x]) {
						minsize = count;
						done = true; break;
					}

					cout << "visiting " << ny << ", " << nx << '\n'; 

					q.push({ ny,nx });
				}
				count++;
				if (done) break;
			}
			answer = max(answer, minsize);

			cout << "\n MINSIZE = " << minsize << endl << endl;
		}
	}
	if (answer == 1) return 0;
	return answer * 2 - 1;
}

int main() {

	cout << solution({ "ABCBA", "DABAG", "EBABH", "FAJAI", "AKLMA" }) << '\n';

	cout << solution({ "ABCBA", "DABAG", "ENABH", "FAJAI", "AKLMO" }) << endl;


}

