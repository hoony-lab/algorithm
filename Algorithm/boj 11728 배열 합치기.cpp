#include <iostream>
#include <vector>
#include <algorithm>
#define F(i,n) for(int i = 0 ; i < n ; ++i)
using namespace std;
int n, m, t;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	F(i, n) cin >> t, v.push_back(t);
	F(i, m) cin >> t, v.push_back(t);

	sort(v.begin(), v.end());

	F(i, (int)v.size()) cout << v[i] << ' ';
	
	return 0;
}