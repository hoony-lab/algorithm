#include <iostream>
#include <stack>
#include <string>
#define FOR(i,n) for(int i = 0 ; i < n ; ++i)
#define endl '\n'
int main() {

	std::stack<int> st;
	std::string s;
	int n;
	std::cin >> n;

	FOR(i, n) {
		int m;
		std::cin >> s;
		if (s == "push") {
			std::cin >> m;
			st.push(m);
		}
		else if (s == "pop") {
			if (!st.empty()) {
				std::cout << st.top() << endl;
				st.pop();
			}
			else std::cout << -1 << endl;
		}
		else if (s == "size")
			std::cout << st.size() << endl;

		else if (s == "empty") {
			if (!st.empty()) std::cout << 0 << endl;
			else std::cout << 1 << endl;
		}
		else if (s == "top") {
			if (!st.empty()) std::cout << st.top() << endl;
			else std::cout << -1 << endl;
		}
	}

}