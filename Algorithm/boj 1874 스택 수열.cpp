#include <iostream>
#include <stack>
#include <string>
std::stack<int> st;
int n, num[100001], check[100001];
std::string s;

int main() {
	std::cin >> n;

	num[0] = 0;

	for (int i = 1; i <= n; ++i) std::cin >> num[i];

	for (int i = 1; i <= n; ++i) {

		if (st.empty()) {
			for (int j = 1; j <= num[i]; ++j) {
				if (check[j]) continue;

				st.push(j);
				s.append("+\n");
			}
			check[st.top()] = 1;
			st.pop();
			s.append("-\n");
		}
		else if (st.top() > num[i]) {
			s = "NO";
			break;
		}
		else if (st.top() == num[i]) {
			check[st.top()] = 1;
			st.pop();
			s.append("-\n");
		}
		else if (st.top() < num[i]) {
			int cnt = 0;
			for (int j = st.top() + 1; j <= num[i]; ++j) {
				if (check[j]) continue;

				st.push(j);
				s.append("+\n");
			}
			check[st.top()] = 1;
			st.pop();
			s.append("-\n");
		}
	}

	std::cout << s;

	return 0;
}