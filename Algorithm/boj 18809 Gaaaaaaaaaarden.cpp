// 202104 1943 - 1830
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 50
#define F(i, n) for(int i = 0 ; i < n ; ++i)
using namespace std;
struct P { int x, y; };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int n, m, g, r, t, max_flower, visit[MAX][MAX];
vector<int> map[MAX][MAX];
vector<P> green, red, possible;
bool check(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= m);
}

void bfs(vector<int> m[][MAX], vector<P> gr, vector<P> re) {

	
}
int main() {
	cin >> n >> m >> g >> r;
	F(x, n) F(y, m) {
		cin >> t, map[x][y].push_back(t);
		if(t == 2) possible.push_back({ x, y });
	}
	vector<int> v;
	F(i, (int)possible.size() - g - r) v.push_back(0);
	F(i, g) v.push_back(1);
	F(i, r) v.push_back(2);

	do {
		//vector<int> tmap[MAX][MAX]{};
		//F(x, n) F(y, m) tmap[x][y] = map[x][y];
		green.clear(), red.clear();

		F(i, v.size()) {
			if (v[i] == 1) green.push_back(possible[i]);
			else if (v[i] == 2) red.push_back(possible[i]);
		}

		bfs(map, green, red);

	} while (next_permutation(v.begin(), v.end()));

	cout << '\n';
	cout << max_flower;

	return 0;
}