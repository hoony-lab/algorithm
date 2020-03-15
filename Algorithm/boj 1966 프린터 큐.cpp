#include <iostream>
#include <queue>
#include <deque>
#include <vector> 
#include <algorithm>

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		std::queue<std::pair<int, int>> q;
		std::priority_queue<int> pq;

		int n, m, tmp, cnt = 0;
		std::cin >> n >> m;

		for (int i = 0; i < n; ++i) {
			std::cin >> tmp;
			q.push(std::make_pair(tmp, i));
			pq.push(tmp);
		}

		while (1) {
			auto p = q.front();
			q.pop();

			if (p.first == pq.top()) {
				pq.pop();
				cnt++;
				if (p.second == m) break;
			}
			else {
				q.push(p);
			}
		}
		std::cout << cnt << '\n';
	}

}
/*
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1

1 9 1 1 1 1

9 1 1 1 1 1
1 1 1 1 1

*/