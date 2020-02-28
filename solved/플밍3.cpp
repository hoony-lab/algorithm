#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int answer = 1, count;
	int n;
	int time[2], start = 1e9, end = 0;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i) {
		cin >> time[0] >> time[1];
		v.push_back({ time[0],time[1] });
		end = max(end, time[1]);
	}
	sort(v.begin(), v.end());
	start = v[0].first - 1;

	int size = v.size();
	for (int i = start; i < end; ++i) {
		cout << "time : " << i << endl;
		count = 0;
		for (int j = 0; j < size; ++j) {
			if (i < v[j].first) break;
			if (i > v[j].first && i < v[j].second) {
				count++;
				cout << "counting :" << j << endl;
			}

		}
		answer = max(answer, count);
	}

	cout << answer;




	return 0;
}