#include "practice.h"

using namespace std;

void practice::q3055()
{
	int r, c, cnt = 0;
	char map[51][51] = { ' ', };
	int visited[51][51] = { 0, };

	cin >> r >> c;	//y, x

	queue<pair<int, int>> q, qStar;

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'S') {
				q.push(make_pair(y, x));
			}
			if (map[y][x] == '*') {
				qStar.push(make_pair(y, x));
			}
		}
	}

	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };
	bool findS = false;

	while (!q.empty()) {
		cnt++;

		int numqStar = qStar.size();
		for (int i = 0; i < numqStar; i++) {
			int txqStar = qStar.front().second;
			int tyqStar = qStar.front().first;
			qStar.pop();
			visited[tyqStar][txqStar] = 1;
			for (int a = 0; a < 4; a++) {
				int mxqStar = dx[a] + txqStar;
				int myqStar = dy[a] + tyqStar;

				if (mxqStar >= 0 && myqStar >= 0 && mxqStar < c && myqStar < r && visited[myqStar][mxqStar] == 0 && (map[myqStar][mxqStar] == '.' || map[myqStar][mxqStar] == 'S')) {
					visited[myqStar][mxqStar] = 1;
					map[myqStar][mxqStar] = '*';
					qStar.push(make_pair(myqStar, mxqStar));
				}
			}
		}

		int numq = q.size();
		for (int i = 0; i < numq; i++) {
			int txq = q.front().second;
			int tyq = q.front().first;
			q.pop();
			visited[tyq][txq] = 1;
			for (int a = 0; a < 4; a++) {
				int mxq = dx[a] + txq;
				int myq = dy[a] + tyq;

				if (mxq >= 0 && myq >= 0 && mxq < c && myq < r  && visited[myq][mxq] == 0) {
					if (map[myq][mxq] == 'D') {
						//cout << "checkmate : " << myq << ", " << mxq << endl;
						visited[myq][mxq] = 1;
						findS = true;
						q.push(make_pair(myq, mxq));
						goto A;
					}
					else if (map[myq][mxq] == '.') {
						//cout << "walking on the : " << myq << ", " << mxq << endl;
						visited[myq][mxq] = 1;
						map[myq][mxq] = 'S';
						q.push(make_pair(myq, mxq));
					}
				}
			}
		}


		//if (findS) break;
		//continue;

		//cout << "start : " << cnt << endl;
		//for (int y = 0; y < r; y++) {
		//	for (int x = 0; x < c; x++) {
		//		cout << map[y][x];
		//	}cout << endl;
		//}
		//cout << endl;
	}
A:
	if (findS)
		cout << cnt;
	else
		cout << "KAKTUS";
}