#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	unordered_map<int, string> ma;
	unordered_map<string, int> inv_ma;

	string s;
	// data
	for (int i = 1; i <= n; i++) {
		cin >> s;
		ma.insert(make_pair(i,s));
		inv_ma.insert(make_pair(s, i));
	}

	//quiz
	for (int i = 0; i < m; i++) {
		cin >> s;
	
		//find num by pokemon
		//there is no easy way to find key by its value
		//therefore, using boost/inverse_map/another map
		if (s[0] > 64) cout << inv_ma[s] << '\n';

		//find pokemon by num
		else cout << ma[stoi(s)] << '\n';	
	}
	
	return 0;
}