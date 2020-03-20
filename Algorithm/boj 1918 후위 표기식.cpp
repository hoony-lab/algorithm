#include <iostream>
#include <string>
#include <stack>
int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);	std::cout.tie(NULL);

	std::stack<char> expr;
	char ch;
	std::string s;
	std::cin >> s;

	for (int i = 0; i < s.length(); ++i) {
		ch = s[i];

		//if (65 <= ch && ch <= 65 + 26) {
		if ('A' <= ch && ch <= 'Z')
			std::cout << ch;

		else if (ch == '*' || ch == '/') {
			while (!expr.empty() && expr.top() != '(' && (expr.top() == '*' || expr.top() == '/')) {
				std::cout << expr.top();
				expr.pop();
			}
			expr.push(ch);
		}
		else if (ch == '+' || ch == '-') {
			while (!expr.empty() && expr.top() != '(') {
					std::cout << expr.top();
					expr.pop();
			}
			expr.push(ch);
		}
		else if (ch == '(') 
			expr.push(ch);
		
		else if (ch == ')') {
			while (expr.top() != '(') {
				std::cout << expr.top();
				expr.pop();
			}
			expr.pop();
		}
	}

	while (!expr.empty()) {
		std::cout << expr.top();
		expr.pop();
	}

	return 0;
}