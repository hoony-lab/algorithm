#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

string solution(string s) {
	string answer = "";
	
	for (int i = 0; i < s.length() ; i++) {

		if (i == 0 || s[i-1] == ' ') s[i] = toupper(s[i]);
		else if (!isdigit(s[i])) {
			i == 0 ? toupper(s[i]) : tolower(s[i]);
		}
		cout << s << endl;
	}

	s.at(0) = toupper(s.at(0));

	//for (int i = 1; i < s.size(); i++) {
	//	if (s.at(i - 1) == ' ') {
	//		s.at(i) = toupper(s.at(i));
	//	}
	//	else {
	//		s.at(i) = tolower(s.at(i));
	//	}
	//}

	return s;
}
int main() {

	//solution("3people unFolloWed me");
	solution("for the last week");

	vector<int> v;

}