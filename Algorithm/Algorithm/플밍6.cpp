#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
	int n, size, maxcol = 0, maxrow = 0;
	string org, num;
	cin >> n >> org;
	vector<pair<int, string>> v;
	for (int i = 0; i < n; ++i) {
		cin >> size >> num;
		v.push_back({ size, num });

		maxcol = max(maxcol, size);
		maxrow += size;
	}

	maxcol = (maxcol * 2) - 1;
	for (int y = 0; y < maxcol; ++y) {

		for (int numcnt = 0; numcnt < n; ++numcnt) {
			for (int x = 0; x < v[numcnt].first; ++x) {
				cout << ".";
				if (v[numcnt].second == "45")
					cout << "#";
			}
		}
		cout << " ";
	}
	return 0;
}