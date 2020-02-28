// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//#define max ((X) > (Y)) ? ((X) : (Y))

using namespace std;
int solution(string S) {
	int answer = 0;
	int len = S.length();
	vector<int> v;
	v.push_back(0);

	for (int i = 0; i < len; i++) {
		string str = S.substr(i, 3);
		if (str == "aaa" || str == "bbb") {
			v.push_back(i + 1);
		}
	}
	v.push_back(len - 1);
	int size = v.size();
	for(int i = 1 ; i < size ; ++i){
		answer = max(answer, v[i] - v[i - 1]);
	}


	
	if (!size) return len;
	else return answer+1;
}

int main() {
	string str1 = "baaabbabbb";
	cout << solution( str1) << endl;
	cout << solution("babba") << endl;
	cout << solution("abaaaa") << endl;


}