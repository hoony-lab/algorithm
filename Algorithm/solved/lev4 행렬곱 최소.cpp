#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int answer;
int result;

void dfs(vector<vector<int>> v, int result, int size) {
	int total = 0;
	int a, b;
	if (size == 1) {
		answer = min(answer, result);
		cout << endl << answer << endl;
		return;
	}

	
	//vector<vector<int>>::iterator it1 = vcopy.begin(), it2 = vcopy.begin();

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (i == j) continue;
			if (v[i][1] != v[j][0] && v[j][0] != v[i][1]) continue;

			vector<vector<int>> vcopy;
			vcopy.assign(v.begin(), v.end());
			cout << size << endl;


			if (v[i][1] == v[j][0]) {
				total = (vcopy[i][0] * vcopy[i][1] * vcopy[j][1]);
				a = v[i][0];	b = v[j][1];
				vcopy.erase(vcopy.begin() + max(i,j));	
				vcopy.erase(vcopy.begin() + min(i,j));
				//vcopy.resize(vcopy.size() - 2);
			}
			else if (v[j][0] == v[i][1]) {
				total = (vcopy[j][0] * vcopy[j][1] * vcopy[i][1]);
				a = v[j][0];	b = v[i][1];
				vcopy.erase(vcopy.begin() + i);	vcopy.erase(vcopy.begin() + j);
				//vcopy.resize(vcopy.size() - 2);
			}
				vcopy.push_back({ a, b });
				dfs(vcopy, result + total, size - 1);


			//total = vcopy[i][0] * vcopy[i][1] * vcopy[j][1];

			cout << total << "  out " << endl;
		}
	}



	return;

}
int solution(vector<vector<int>> matrix_sizes) {
	answer = 1e9;
	result = 0;

	dfs(matrix_sizes, result, matrix_sizes.size());

	return answer;
}

int main() {

	cout << solution({ { 5,3 }, { 3,10 }, { 10,6 } });


}