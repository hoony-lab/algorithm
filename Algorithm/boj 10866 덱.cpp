#include <iostream>
#include <deque>
#include <string>
#define FOR(i,n) for(int i = 0 ; i < n ; ++i)
#define endl '\n'
int main() {

	std::deque<int> deq;
	std::string s;
	int n;
	std::cin >> n;

	FOR(i, n) {
		int m;
		std::cin >> s;
		if (s == "push_front") {
			std::cin >> m;
			deq.push_front(m);
		}
		else if (s == "push_back") {
			std::cin >> m;
			deq.push_back(m);
		}
		else if (s == "pop_front") {
			if (!deq.empty()) {
				std::cout << deq.front() << endl;
				deq.pop_front();
			}
			else std::cout << -1 << endl;
		}
		else if (s == "pop_back") {
			if (!deq.empty()) {
				std::cout << deq.back() << endl;
				deq.pop_back();
			}
			else std::cout << -1 << endl;
		}
		else if (s == "size")
			std::cout << deq.size() << endl;

		else if (s == "empty") {
			if (!deq.empty()) std::cout << 0 << endl;
			else std::cout << 1 << endl;
		}
		else if (s == "front") {
			if (!deq.empty()) std::cout << deq.front() << endl;
			else std::cout << -1 << endl;
		}
		else if (s == "back") {
			if (!deq.empty()) std::cout << deq.back() << endl;
			else std::cout << -1 << endl;
		}
	}

}