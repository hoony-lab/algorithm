#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int len, c;
char letter[16];
vector<int> v;
int main() {
	cin >> len >> c;
	for (int i = 0; i < c; ++i) {
		cin >> letter[i];
		v.push_back(1);
	}
	sort(letter, letter + c);

	for (int i = 0; i < len; ++i) v[i] = 0;
	do {
		string ans = "";
		for (int i = 0; i < c; i++) {
			if (v[i] == 0) {
				ans = ans + letter[i];
			}
		}
		int cnt1 = 0;	//모음 개수
		int cnt2 = 0;	//자음 개수
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i'
				|| ans[i] == 'o' || ans[i] == 'u')
				cnt1++;
			else cnt2++;
		}

		if (cnt1 < 1 || cnt2 < 2) continue;

		cout << ans << '\n';
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}