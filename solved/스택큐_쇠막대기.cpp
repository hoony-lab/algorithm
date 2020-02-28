#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
	int answer = 0;
	stack<int> s;
	
	for (int i = 0; i < arrangement.length(); i++) {
		if (arrangement[i] == '(') {
			s.push(1);
		}
		else {
			s.pop();
			if (arrangement[i - 1] == '(')
				answer += s.size();
			else
				answer += 1;
		}
	}
	return answer;
}

int main() {
	/*
	arrangement				return
	()(((()())(())()))(())	17
	*/
	
	cout <<  solution("()(((()())(())()))(())");


}