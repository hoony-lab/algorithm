#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define FS(i, n, m) for(int i = m ; i < n ; ++i)
#define FR(i, n) for(int i = n - 1; i >= 0 ; --i)
using namespace std;
using vvi = vector<vector<int>>;
using vvs = vector<vector<string>>;
using vi = vector<int>;


vector<int> solution(vector<string> gems) {
	vector<int> answer = { 100000, 100000 };
	set<string> st;
	map<string, int> mp;

	for (string gem : gems) {
		st.insert(gem);
		mp[gem]++;
	}
	//cout << st.size() << ", " << gems.size();

	if (st.size() == gems.size()) return { 1, (int)gems.size() };
	if (st.size() == 1) return { 1, 1 };
	

	int min_len = 1e9, min_start = 1e9;
	for (int start = 0; start < gems.size() - st.size(); ++start) {
		int cnt = 0, end = 0;
		map<string, int> check;

		for (int end = start; end < gems.size(); ++end) {

			if (++check[gems[end]] == 1) 
				if (++cnt == st.size()) {
					if (min_len == end - start && answer[0] > start + 1 ) {
						answer = { start + 1, end + 1 };
					}
					else if (min_len > end - start) {
						min_len = end - start;
						answer = { start + 1, end + 1 };
					}
				}
		}
	}

	//0	3 4 7
	//1 2
	//	5
	//	6
	
	return answer;
}


int main() {

	//auto a = solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });			// 3, 7
	//auto b = solution({ "AA", "AB", "AC", "AA", "AC" });		// 1, 3
	//auto c = solution({ "XYZ", "XYZ", "XYZ" });					// 1, 1
	vi d = solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });	// 1, 5

	for (int i : d) {
		cout << i << ", ";
	}

	return 0;
}