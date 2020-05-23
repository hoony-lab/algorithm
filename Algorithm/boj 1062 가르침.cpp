#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
string prefix = "anta", suffix = "tica", tmp;
map<char, int> mp;
int ans;
int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		tmp = tmp.substr(4, tmp.length() - 8);
		for (auto c : tmp) {
			mp[c]++;
		}
	}
	for (auto c : mp) {
		cout << c.first << '\n';
	}
	cout << ans << '\n';
	return 0;
}