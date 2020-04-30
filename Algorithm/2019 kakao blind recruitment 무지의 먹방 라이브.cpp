#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;
vector<pair<int, int>> v;
//ll left_food[200001];
//map<ll, ll> left_food, extra_eat;

void print(vector<pair<int, int>> v) {
	for (auto p : v) 
		cout << p.first << ", " << p.second << '\n';
	cout << "\n\n";

}
int solution(vector<int> food_times, ll k) {
	ll fsize = food_times.size();
	ll round = k / food_times.size();
	ll remain_turn = k % food_times.size();
	ll all_eat_cnt = 0;
	
	for (int i = 0; i < fsize; ++i) 
		v.push_back({ food_times[i], i + 1 });
	
	sort(v.begin(), v.end(), [](auto v1, auto v2) {
		if (v1.first == v2.first)
			return v1.second < v2.second;
		return v1.first < v2.first;
	});

	//print(v);

	ll extra_eat = 0;
	for (int i = k + 1; i <= fsize+k; ++i) {
		i %= fsize+1;

		round = v[i].second <= remain_turn ? round + 1 : round;

		ll left_food = (v[i].first - round);
		left_food -= extra_eat;

		//cout << v[i].first << ", " << v[i].second << " << " << left_food << " :::: " <<  extra_eat << '\n';

		if (left_food > 0) return v[i].second;

		extra_eat = left_food;
	}

	return -1;
}




int main() {
	cout << solution({ 3,1,2 }, 5);     // 1
	return 0;
}