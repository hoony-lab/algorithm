#include <string>
#include <vector>

using namespace std;
/*
1 4     3 3
3 2     3 3
4 1

2 3 2       5 4 3
4 2 4       2 4 1
3 1 3       3 1 1
xy
00 00   00 01   00 02
01 10   01 11   01 12
02 20   02 21   02 22

10 00   10 01
11 10   11 11
12 20   12 12
*/
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	int x1_size = arr1.size();
	int y2_size = arr2[0].size();
	int xy_size = arr2.size();
	for (int x1 = 0; x1 < x1_size; x1++) {
		vector<int> row;
		row.clear();
		for (int y2 = 0; y2 < y2_size; y2++) {
			int total = 0;
			for (int xy = 0; xy < xy_size; xy++) {
				total += arr1[x1][xy] * arr2[xy][y2];
			}
			row.push_back(total);
		}

		answer.push_back(row);
	}

	return answer;
}