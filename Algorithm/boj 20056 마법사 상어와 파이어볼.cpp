// https://www.acmicpc.net/problem/20056
#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <memory>
using namespace std;
#define F(i, n) for(int i = 0 ; i < n ; ++i)

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int odd[] = { 1,3,5,7 };
int even[] = { 0,2,4,6 };

struct Fireball {
	// À§Ä¡ r, c Áú·® m ¼Ó·Â s ¹æÇâ d
	int r, c, m, s, d;
};
int n, m, k, result;
vector<Fireball> map[51][51], tmap[51][51];
vector<Fireball> ball, new_ball;

void print(vector<Fireball> m[][51]) {
	F(x, n) {
		F(y, n) {
			if (map[x][y].size()) {
				int summ = 0;
				F(i, m[x][y].size()) summ += m[x][y][i].m;

				cout << summ << " ";
			}
			else cout << "0 ";
		}
		cout << '\n';
	}
	cout << '\n';
}
void divide() {
	F(x, n) F(y, n) tmap[x][y].clear();
	new_ball.clear();

	F(x, n) F(y, n) if (map[x][y].size() >= 2) {
		
		// È¦¼ö ´ë°¢¼±, Â¦¼ö ¼öÁ÷¼öÆò
		bool is_first_dir_odd = map[x][y].front().d & 1;
		bool is_all_same = true;

		int summ = 0, sums = 0, ball_count = (int)map[x][y].size();
		int nm = 0, ns = 0;
		F(i, ball_count) {
			summ += map[x][y][i].m;
			sums += map[x][y][i].s;
			bool is_cur_dir_odd = ball[i].d & 1;
			
			if (ball_count && is_all_same) {
				// XOR È¦Â¦ Â¦È¦
				if (is_cur_dir_odd ^ is_first_dir_odd) 
					is_all_same = false;
			}
		}

		nm = summ / 5;
		ns = sums / ball_count;

		// Áú·®ÀÌ ÀÖÀ» ¶§ 4ºÐÇÒ
		F(a, 4) {
			int nx, ny, nd;
			// Â¦ ¹æÇâ
			if (is_all_same) {
				//nx = (1000 * n + x + dx[even[a]]) % n;
				//ny = (1000 * n + y + dy[even[a]]) % n;
				nd = even[a];
			}
			else {
				//nx = (1000 * n + x + dx[odd[a]]) % n;
				//ny = (1000 * n + y + dy[odd[a]]) % n;
				nd = odd[a];
			}

			//new_map[nx][ny].push_back({ nx, ny, nm, ns, nd });
			//new_ball.push_back({ nx, ny, nm, ns, nd });
			tmap[x][y].push_back({ x, y, nm, ns, nd });
			new_ball.push_back({ x, y, nm, ns, nd });
			cout << "push at : " << x << ", " << y << '\n';
		}

		F(x, n) F(y, n) map[x][y].clear();
		memcpy(map, tmap, sizeof(map));

		ball.clear();
		ball = new_ball;
	}
}
void move_and_join() {
	F(x, n) F(y, n) tmap[x][y].clear();

	F(i, (int) ball.size()) {
		int nx = (1000 * n + ball[i].r + ball[i].s * dx[ball[i].d]) % n;
		int ny = (1000 * n + ball[i].c + ball[i].s * dy[ball[i].d]) % n;

		ball[i].r = nx, ball[i].c = ny;
		tmap[nx][ny].push_back(ball[i]);
	}
	memcpy(map, tmap, sizeof(map));
}

void solve() {

	while(k--) {
		cout << "k : " << k << '\n';
		print(map);
		cout << "ball : " << ball.size() << '\n';
		move_and_join();
		print(map);
		cout << "ball : " << ball.size() << '\n';
		divide();
		print(map);
		cout << "ball : " << ball.size() << '\n';
		cout << "\n\n";
	}

	F(i, (int)ball.size()) result += ball[i].m;
}

void init() {
	cin >> n >> m >> k;
	F(i, m) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		ball.push_back({ r - 1, c - 1, m, s, d });
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	init();
	solve();

	cout << result;

}