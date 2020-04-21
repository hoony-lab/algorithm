#include <iostream>
#include <queue>
#include <cstring>
int n, a, b, ans = 1e9;
bool visitf[500001][30], visits[500001][30], flag = false;
int d[] = { -1, 1 };

struct pos {
	int pos, time;
};

void bfs(std::queue<pos> q) {

	while (!q.empty()) {

		int qsize = q.size();
		for (int i = 0; i < qsize; ++i) {

			int pos = q.front().pos;
			int time = q.front().time;
			q.pop();

			//std::cout << "pos : " << pos << " : " << time << '\n';

			for (int a = 0; a < 2; ++a) {
				int npos = pos + (1 << time) * d[a];
				int ntime = time + 1;
				if (npos < 1 || npos > n) continue;

				if (!flag) {
					if (visitf[npos][ntime]) continue;
					else visitf[npos][ntime] = true;
				}
				else {
					if (visits[npos][ntime]) continue;
					else {
						if (visitf[npos][ntime]) {
							ans = ntime;
							return ;
						}
						else visits[npos][ntime] = true;
					}
				}

				q.push({ npos, time + 1 });
			}
		}
	}
}


int main() {
	std::cin >> n >> a >> b;

	memset(visits, false, sizeof(visits));
	memset(visitf, false, sizeof(visitf));

	std::queue<pos> qf, qs;
	qf.push({ a, 0 }), qs.push({ b, 0 });
	visitf[a][0] = visits[b][0] = true;

	bfs(qf);
	flag = true;
	bfs(qs);

	if (ans == 1e9) std::cout << -1;
	else std::cout << ans;

	/*
	while (!q.empty()) {
		std::cout << "time : " << ans << " jump : " << jump << "\n\n";

		int qsize = q.size();
		for (int i = 0; i < qsize; ++i) {

			int f = q.front().five;
			int s = q.front().six;
			q.pop();
			std::cout << f << " : " << s << '\n';

			for (int a = 0; a < 2; ++a) {
				for (int b = 0; b < 2; ++b) {
					int nf = f + jump * d[a];
					int ns = s + jump * d[b];

					if (nf < 1 || nf > n || ns < 1 || ns > n) continue;
					if (visit[0][nf] || visit[1][ns]) continue;

					if (nf == ns) {
						std::cout << ans + 1;
						return 0;
					}

					q.push({ nf, ns });
					visit[0][nf] = visit[1][ns] = ans;
				}
			}
		}

		jump <<= 1;
		if (jump > n) {
			std::cout << -1;
			return 0;
		}
		ans++;
	}*/


	return 0;
}

/*
10 4 10

2
*/