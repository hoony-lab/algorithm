#include <iostream>
#include <queue>
int n, a, b, ans, jump, done;

struct pos {
	int five, six;
};

int main() {
	std::cin >> n >> a >> b;

	std::queue<pos> q;
	q.push({ a, b });

	while (!q.empty()) {

		int qsize = q.size();
		for (int i = 0; i < qsize || !done; ++i) {

			int f = q.front().five;
			int s = q.front().six;
			q.pop();

			if (f == s || jump > n) { done = true; break; }

			if (f - jump > 0 && s - jump > 0)
				q.push({ f - jump, s - jump });

			if (f - jump > 0 && s + jump <= n)
				q.push({ f - jump, s + jump });

			if (f + jump <= n && s - jump > 0)
				q.push({ f + jump, s - jump });

			if (f + jump <= n && s + jump <= n)
				q.push({ f + jump, s + jump });

			std::cout << ans;
		}

		jump << 1;
		ans++;
	}

	if (jump > n) ans = -1;
	std::cout << ans;

	return 0;
}

/*
10 4 10

2
*/