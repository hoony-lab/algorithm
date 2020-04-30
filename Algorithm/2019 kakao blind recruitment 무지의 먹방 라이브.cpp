#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm >
typedef long long ll;
using namespace std;

set<int> s;
int solution(vector<int> food_times, ll k) {
	//int answer = 0;
	//ll foods = 0;
	//ll round = k / food_times.size();
	//ll post = k % food_times.size();
	//ll all_eat_cnt = 0;

	//for (int i = 0; i < food_times.size(); ++i) {

	//	ll eat = i < post ? round : round + 1;
	//	foods += food_times[i];

	//	if (food_times[i] <= eat)
	//		all_eat_cnt++;


	//}

	//if (foods < k)
	//	return -1;


	int answer = 0;

	ll sum = 0;
	vector<pair<int, int>> v;
	for (int i = 0; i < food_times.size(); ++i) {
		v.push_back({ food_times[i], i });
		sum += food_times[i];
	}
	sort(v.begin(), v.end());

	//sort(v.begin(), v.end(), [](pair<int, int> p1, pair<int, int> p2) {
	//	if (p1.first == p2.first)
	//		return p1.second < p2.second;
	//	return p1.first < p2.first;
	//});


	for (pair<int, int> p : v) {
		ll time = (ll)(p.first - 0);

		p.first;
		p.second;
	}



	return -1;
}




int main() {
	cout << solution({ 3,1,2 }, 5);     // 1
	return 0;
}