// you can use includes, for example:
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

	/*
	첫째 가로줄합 = U
	둘째 가로줄의 합 = L
	K번째 세로의 합 = C[K]
	3 2
	{2,1,1,0,1}
	 1 1 0 0 1
	 1 0 1 0 0
	*/

string solution(int U, int L, vector<int> &C) {
	string answer = "";
	int up = U, low = L;
	int count_one = 0, count_two = 0, count_zero = 0, total = 0;
	string str[2] = { "", "" };

	int size = C.size();
	for (int i = 0; i < size; ++i) {

		if (C[i] == 2) {
			++count_two;
			str[0] += to_string(1);
			str[1] += to_string(1);
			--up;   --low;
		}
		else if (C[i] == 1) {
			++count_one;
			if (up > low) {
				str[0] += to_string(1);
				str[1] += to_string(0);
				--up;
			}
			else {
				str[0] += to_string(0);
				str[1] += to_string(1);
				--low;
			}

		}
		else if (C[i] == 0) {
			++count_zero;
			str[0] += to_string(0);
			str[1] += to_string(0);
		}
		total += C[i];
	}
	
	//cout << str[0] + "," + str[1] << endl;


	if (total != U + L) answer = "IMPOSSIBLE";
	else answer = str[0] + "," + str[1];

	return answer;
}


int main() {
	vector<int> test1 = { 2, 1, 1, 0, 1 };
	vector<int> test2 = { 0,0,1,1,2 };
	vector<int> test3 = { 2,0,2,0 };



	cout << solution(3, 2, test1) << '\n';
	cout << solution(2, 3, test2) << '\n';
	cout << solution(2, 2, test3) << '\n';
	



}