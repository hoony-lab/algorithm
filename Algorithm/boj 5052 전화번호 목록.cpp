#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define YES std::cout << "YES\n";
#define NO std::cout << "NO\n";

int t, n;
struct Trie {
	char c;
	int count;
	std::map<char, char> m[10];
}root;

bool search(std::string s) {
	std::string tmp;

	if(s == tmp) return true;
}

void insert(std::string s) {
	if (search(s)) return;

	Trie currentNode = root;

	for (char c : s) {
		//Trie c = currentNode.m['a'];
		//if () {

		//}
		//else {
		//	
		//}
	}
	
	
}

int main() {
	std::cin >> t;
	while (t--) {
		bool fail = false;
		std::string num[10001];
		std::cin >> n; F(i, n) std::cin >> num[i];

		std::sort(num, num + n);

		F(a, n - 1) {
			if (num[a] == num[a + 1].substr(0, num[a].length())) {
				NO; fail = true; break;
			}
		}
		if (!fail) YES;
	}

	std::cin >> t;
	while (t--) {
		bool fail = false;
		std::string s;
		std::cin >> n; F(i, n) {
			std::cin >> s;
			
		}
	}
	return 0;
}
