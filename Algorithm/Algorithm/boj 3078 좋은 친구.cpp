#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;
bool complete[300001];
long long answer;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	answer = 0;

	int n, k;
	string str;
	vector<string> v;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		v.push_back(str);
	}

	memset(complete, false, sizeof(complete));
	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i)
	{
		if (complete[i]) continue;
		for (int j = 0; j < n; ++j)
		{
			if (complete[j] || i == j) continue;

			if (v[i].size() == v[j].size() &&
				abs(i - j) <= k) {
				complete[i] = true;
				complete[j] = true;
				answer++;
				break;
			}
		}
	}
	cout << answer << '\n';





	return 0;

}