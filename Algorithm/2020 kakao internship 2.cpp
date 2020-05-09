#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define FS(i, n, m) for(int i = m ; i < n ; ++i)
#define FR(i, n) for(int i = n - 1; i >= 0 ; --i)
using namespace std;
using vvi = vector<vector<int>>;
using vvs = vector<vector<string>>;
using vi = vector<int>;

long long cal(int order[]) {
	for (int i = 0; i < 3; ++i) {
		
	}
}
long long solution(string expression) {
	long long answer = 0;
	string tmp;
	vector<int> num;
	vector<char> op;
	for (int i = 0; i < expression.length(); ++i) {

		if ('0' <= expression[i] && expression[i] <= '9') {
			tmp.insert(tmp.end(), expression[i]);

			if (i == expression.length() - 1)
				num.push_back(stoi(tmp));
		}
		else {
			op.push_back(expression[i]);
			num.push_back(stoi(tmp));
			tmp = "";
		}
	}
	
	int order[] = { 0,1,2 };
	do {
		cal(order);
	} while (next_permutation(order, order + 3));
	


	for (auto i : num)
		cout << i << ", ";
	cout << '\n';
	for (auto i : op)
		cout << i << ", ";
	cout << '\n';



	return answer;
}


int main() {
	
	cout << solution("100-200*300-500+20") << '\n';		// 60420
	cout << solution("50*6-3*2") << '\n';				// 300

	return 0;
}