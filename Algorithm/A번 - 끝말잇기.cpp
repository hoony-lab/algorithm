#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, ans, len;
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    cout.tie(NULL);
	
	cin >> n;
	vector<string> v(n);

	for (int i = 0; i < n; ++i) 
		cin >> v[i];
	
	for (int i = 0; i < n - 1; ++i) {
		if (v[i][v[i].length() - 1] != v[i + 1][0]) {
			cout << 0;
			return 0;
		}
	}

	cout << 1;
	return 0;
}