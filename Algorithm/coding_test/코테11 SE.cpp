#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> v;
int money_total, ans, min_gap=987654321;
bool visited[1001];

void search(int sum) {

	if(money_total/2 == sum){
		ans = 0;
		return;
	}
	if (money_total - sum != 0 && abs(money_total - sum) < min_gap) {
		min_gap = abs(money_total - sum);
	}
	
//	cout << sum << ", " << min_gap << '\n';

	int money_size = v.size();
	for (int i = 0; i < v.size(); i++) {
		if (visited[i]) continue;
		visited[i] = true;
		search(sum + v[i]);
		sum -= v[i];

		visited[i] = false;
	}
}

	map<char, int> m, mcheck;
	bool isAnswer;

int solution2(string S, string pattern) {
	int ans = 0;
	//int m[27];

	for (int i = 0; i <= S.size() - pattern.size(); ++i) {

		m.clear();
		for (char ch : pattern) m[ch]++;
		isAnswer = true;

		for (int j = i; j < pattern.size(); ++j) 
			mcheck[S[j]]--;

		for (int j = i; j < pattern.size(); ++j) {
			//cout << pattern[j] << "/" << mcheck[pattern[j]] << ", ";
			if (mcheck[pattern[j]] != 0) {
				isAnswer = false; break;
			}
		}
		if (isAnswer) ans++;
	}
	return ans;
}


int main() {
	//vector<vector<int>> money = { {100,3},{200,1},{50,2} };
	////vector<vector<int>> money = { {2500,3}, {700,5} };

	//
	////{50, 50, 100, 100, 100, 200};

	//for (int i = 0; i < money.size(); i++) {
	//	for (int j = 0; j < money[i][1]; j++) {
	//		v.push_back(money[i][0]);
	//		money_total += money[i][0];
	//	}
	//}
	//cout << money_total << '\n';

	//search(0);

	//cout << min_gap;





	cout << solution2("tegsornamwaresomran", "ransom") << '\n';
	//cout << solution2("wreawerewa", "ware");


	return 0;
}