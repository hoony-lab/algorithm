#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define FOR(i,n) for(int i = 0 ; i < n ; ++i)
using namespace std;
int main() {

	vector<string> v;

	int n;
	std::cin >> n;
	FOR(i, n) {
		std::string s;
		std::cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), [](string v1, string v2) {
		if (v1.length() == v2.length())
			return v1 < v2;
		else return v1.length() < v2.length();
	});

	//consider overlapping -> unique / other data structure

	unique(v.begin(), v.end());
	
	FOR(i, n) std::cout << v[i] << '\n';

	return 0;
}