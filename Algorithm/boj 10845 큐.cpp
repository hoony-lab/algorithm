#include <iostream>
#include <queue>
#include <string>
#define FOR(i,n) for(int i = 0 ; i < n ; ++i)
#define endl '\n'
int main() {

	std::queue<int> que;
	std::string s;
	int n;
	std::cin >> n;

	FOR(i, n) {
		int m;
		std::cin >> s;
		if (s == "push") {
			std::cin >> m;
			que.push(m);
		}
		else if (s == "pop") {
			if (!que.empty()) {
				std::cout << que.front() << endl;
				que.pop();
			}
			else std::cout << -1 << endl;
		}
		else if (s == "size")
			std::cout << que.size() << endl;

		else if (s == "empty") {
			if (!que.empty()) std::cout << 0 << endl;
			else std::cout << 1 << endl;
		}
		else if (s == "front") {
			if (!que.empty()) std::cout << que.front() << endl;
			else std::cout << -1 << endl;
		}
		else if (s == "back") {
			if (!que.empty()) std::cout << que.back() << endl;
			else std::cout << -1 << endl;
		}
	}

}