#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

string solution(string s) {
	string answer = "";
	
	for (int i = 0; i < s.length() ; i++) {

		if (i == 0 || s[i-1] == ' ') toupper(s[i].c_str());
		else if (!isdigit(s[i])) {
			i == 0 ? toupper(s[i]) : tolower(s[i]);
		}
		cout << s << endl;
	}

	std::cout << s << endl;
	return s;
}
int main() {

	//solution("3people unFolloWed me");
	solution("for the last week");

	vector<int> v;

}