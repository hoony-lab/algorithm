#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

int solution(string s)
{
	string::iterator it = s.begin()+1;
	for (it ; it != s.end(); )
	{
		if (*it == *(it - 1)) {
			cout << s.size() << endl;
			if (s.size() == 2) return 1;
			s.erase(it-1, it+1 );
			cout << *it << endl;
			if(it != s.begin()) it -= 1;
			cout << s << endl;
		}
		else {
			it++;
			
		}
	}
	return 0;
	cout << endl << s;
/*
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1])

	}*/
	return 1;
}
int main() {
	cout << solution("abcdeffgthbbb");
	//1


}