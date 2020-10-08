#include <iostream>
#include <vector>
#include <math.h>
#include <memory.h>
using namespace std;
struct P { int x, y; };
// home, conv... , fest
// 50 미터에 한병

int t, n, x, y, beer = 1000, visit[123], done;
vector<P> v;
bool cal_beer(int n1, int n2) {
	return abs(v[n2].x - v[n1].x) + abs(v[n2].y - v[n1].y) <= 1000;
}

void dfs(int idx) {
	visit[idx] = true;

	for (int i = 1; i < n + 2; ++i) {
		if (visit[i] || !cal_beer(idx, i)) continue;

		dfs(i);
	}
}
int main() {
	cin >> t;
	while (t--) {
		done = false;
		v.clear();
		memset(visit, 0, sizeof(visit));
		
		cin >> n;
		for (int i = 0; i < n + 2; ++i) 
			cin >> x >> y, v.push_back({ x,y });
		
		dfs(0);
		cout << (visit[n+1] ? "happy\n" : "sad\n");
	}

	return 0;
}
/*
2
2
0 0
1000 0
1001 1000
2000 1000
2
0 0
1000 0
2000 1000
2000 2000
*/