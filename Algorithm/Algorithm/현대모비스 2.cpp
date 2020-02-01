#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
적산 주행거리가 작은차부터 대여
if(거리가같으면) 차량번호가 앞서는 차 우선

차 대수 n
차량번호 문자열 plates
주행거리 정수 odo
차량대여 고객수 k
차량 대여후 주행거리 drives
*/
string solution(int n, vector<string> plates, vector<int> odo, int k, vector<int> drives) {
	int min_odo, min_car;
	//차량 번호 + 해당 차량 적산주행거리
	vector<pair<string, long long> > cars;
	for (int i = 0; i < n; ++i)
		cars.push_back({ plates[i], odo[i] });

	// 적산주행거리 우선, 차량 번호 차선 올림차순 정렬 16 18 19 20 20 24
	sort(cars.begin(), cars.end(), [](pair<string, int> v1, pair<string, int> v2) {
		if (v1.second == v2.second) return v1.first < v2.first;
		else return v1.second < v2.second;
	});

	min_odo = cars[0].second;
	min_car = 0;


	//k 번의 차량 대여
	for (int time = 0; time < k + 1; ++time) {

		//for (int i = 0; i < n; ++i) {
		//	if (min_odo < cars[i].second) continue;

		//	if (min_odo > cars[i].second) {
		//		
		//		min_odo = cars[i].second;
		//		min_car = i;
		//	}
		//	else if (min_odo == cars[i].second) {
		//		if (cars[min_car].first > cars[i].first) {
		//			min_odo = cars[i].second;
		//			min_car = i;
		//			break;
		//		}
		//	}
		//}
		// 적산주행거리 우선, 차량 번호 차선 올림차순 정렬 16 18 19 20 20 24
		sort(cars.begin(), cars.begin()+n, [](pair<string, int> v1, pair<string, int> v2) {
			if (v1.second == v2.second) return v1.first < v2.first;
			else return v1.second < v2.second;
		});


		if (k != time) {
			cars[min_car].second += drives[time];
			//min_odo += drives[time];
		}
	}

	return cars[min_car].first;
}
int main() {
	cout << solution(6, { "AZ3618", "XP9657", "SP6823", "UH7515", "TV6621", "WZ8264" }, { 20,16,18,20,24,19 }, 8, { 3,7,5,8,6,5,10,2 }) << '\n';



}