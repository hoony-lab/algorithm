#include <iostream>
#include <vector>
#define ll long long
#define MAX 123458
using namespace std;

struct island {
	char t; ll a = 0;
};

int n;
vector<int> map[MAX];
vector<island> v;

ll go(int i) {
	ll sum = 0;
	for (int j = 0; j < map[i].size(); j++) {
		sum += go(map[i][j]);
	}

	if (v[i].t == 'S')
		return sum + v[i].a;
	else
		return sum >= v[i].a ?
				sum - v[i].a : 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;

	v.push_back({ 'S', 0 });

	for (int i = 1; i < n; i++) {
		char tt; ll ta, tp;
		cin >> tt >> ta >> tp;

		// one-way 단방향, 아래 서 위로 저장
		map[tp - 1].push_back(i);
		v.push_back({ tt, ta });
	}

	cout << go(0);
	return 0;
}