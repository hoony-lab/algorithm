#include <list>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <iostream>
using namespace std;
//
//int solution(vector<int> weight) {
//	int size = weight.size();
//	int total = 0, ind = 0, max = 0;
//	sort(weight.begin(), weight.end());
//	//1 1 2 3 6 7 30
//
//	set<int> nums;
//	vector<int> v;
//
//	for (auto i : weight) {
//		max += i;
//		//nums.insert(i);
//		v.push_back(i);
//	}
//	//nums.insert(max);
//	v.push_back(max);
//
//	do {
//		total = 0;
//		ind = size - 2;
//
//		while (ind) {
//			total = 0;
//			for (int i = ind; i >= 0; --i) {
//				total += weight[i];
//			}
//			--ind;
//			v.push_back(total);
//			//nums.insert(total);
//			//cout << total << endl;
//		}
//	} while (next_permutation(weight.begin(), weight.end()));
//
//	//cout << nums.size() << endl << endl;
//	//for (auto i : nums) {
//	//	cout << i << endl;
//	//}
//	/*
//	0 1 2 3 4 5 6 7
//	1 2 3 4 5 6 8 9
//	*/
//	sort(v.begin(), v.end());
//	
//	vector<int>::iterator it = (v.begin(), v.end());
//	v.reserve(it);
//	cout << v.size();
//
//
//	for (auto i : v) {
//		cout << i << "\t";
//	}
//	int searching = 0;
//	int start = 0, end = max - 1;
//	set<int>::iterator it;
//	while (searching <= max) {
//		
//		searching = (start + end) / 2;
//
//		cout << searching << endl;
//		if (searching == v[searching] &&
//			searching + 1 > v[searching+1])
//			return searching;
//
//			if (searching == v[searching]) {
//				start = searching + 1;
//			}
//			else if (searching > v[searching]){
//				end = searching - 1;
//			}
//
//
//
//
//		//it = nums.find(searching);
//		//if (it == nums.end()) return searching
//		//else nums.erase(it);
//		//else nums.erase(nums.find(searching
//		//++searching;
//	}
//
//	
//	return -1;
//}
//int main() {
//	cout << solution({ 3, 1, 6, 2, 7, 30, 1 });
//	//21
//
//
//
//}

//vector<int> v;
int answer = 1;

int solution(vector<int> weight) {
	sort(weight.begin(), weight.end());

	for (auto i : weight)
		cout << i << " ,";
	cout << '\n';

	for (int i = 0; i < weight.size(); i++){
		if (weight[i] > 1 + answer) break;
			answer += weight[i];
	}

	return answer;

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(false);	cout.tie(false);

	cout << solution({ 3,1,6,2,7,30,1 });


}