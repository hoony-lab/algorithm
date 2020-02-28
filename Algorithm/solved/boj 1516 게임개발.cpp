#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, temp;
	vector<vector<int>> v;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		vector<int> v_temp;
		v_temp.clear();

		while (1) {
			cin >> temp;
			if (temp == -1) break;
			else v_temp.push_back(temp);

		}
		v.push_back(v_temp);
	}

	
	for (int building = 0; building < n; ++building) {
		if (v[building].size() == 1) cout << v[building].front() << '\n';
		else {
			int size = v[building].size();
			int time = v[building].front();
			for (int pre = size - 1; pre > 0 ; --pre) {
				time += v[pre - 1].front();
				
			}
			v[building][0] = time;
			cout << time << '\n';
		}
	}





	return 0;
}