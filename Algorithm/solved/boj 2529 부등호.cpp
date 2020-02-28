#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*

2
< >

897
021

*/

char next_nums[10] = { 0,1,2,3,4,5,6,7,8,9 };
char prev_nums[10] = { 9,8,7,6,5,4,3,2,1,0 };
char arr[11] = {};
bool visited[11] = { };
int k;
vector<string> v, vtemp;

void dfs(int cnt) {
	
	// pruning
	if (cnt == k + 1) {
		for (int i = 0; i < k; i++){

			if (arr[i] == '<') {
				if (vtemp[i] > vtemp[i + 1]) return;
			}
			else {
				if (vtemp[i] < vtemp[i + 1]) return;
			}
		}


		string temp = "";
		for (int i = 0; i < vtemp.size(); i++)
			temp += vtemp[i];
		v.push_back(temp);

		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!visited[i]) {
			vtemp.push_back(to_string(i));
			visited[i] = true;
			dfs(cnt + 1);
			visited[i] = false;
			vtemp.pop_back();
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;

	for (int i = 0; i < k; i++)
		cin >> arr[i];

	dfs(0);

	cout << v[v.size() - 1] << '\n';
	cout << v[0] << '\n';
	
}