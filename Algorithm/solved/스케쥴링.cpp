#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> jobs) {
	int answer = 0, time = 0;
	sort(jobs.begin(), jobs.end(), [time](vector<int> v1, vector<int> v2) {
		//if (v2[0] <= v1[0]) return v1[1] < v2[1];
		if (v1[0] == v2[1]) return v1[0] < v2[0];
		else return v1[1] < v2[1];
	});
	/*
	if (v1[1] < v2[1])
			return v1[0] < v1[0];
		else 
	*/

	answer += jobs[0][1] + jobs[0][0];
	time += jobs[0][1] + jobs[0][0];
	cout << answer << endl;

	for (int i = 1; i < jobs.size(); i++) {
		//cout << jobs[i][0] << ", " << jobs[i][1] << " , " << jobs[i - 1][1] + jobs[i][1] - jobs[i][0] << endl;

		//시작시간이 스케쥴 뒤
		if (time <= jobs[i][0]) {
			answer += jobs[i][1] - jobs[i][0];
			time = time + jobs[i][1];
		}
		//시작시간이 스케줄 앞
		else {
			answer += time - jobs[i][0] + jobs[i][1];
			time += jobs[i][1];
		}

		
	}

/*
	vector<vector<int>>::iterator it;

	int size = jobs.size();

	sort(jobs.begin(), jobs.end(), [time](vector<int> v1, vector<int> v2) {
		return v1[0] < v2[0];
	});
	int time = jobs.front[0] + jobs.front[1];
	int answer = time;

	it = jobs.begin();
	jobs.erase(it);


	for (int i = 1; i < size; i++)
	{
		if ( time < ) {
			sort(jobs.begin(), jobs.end(), [time](vector<int> v1, vector<int> v2) {
				return v1[0] < v2[0];
			});
			time += jobs.front[0] + jobs.front[1];

			it = jobs.begin();
			jobs.erase(it);

		}
		else {
			sort(jobs.begin(), jobs.end(), [time](vector<int> v1, vector<int> v2) {
				return v1[1] < v2[1];
			});



			it = jobs.begin();
			jobs.erase(it);
		}
	}*/


	cout << answer / jobs.size() << endl;
	return answer / jobs.size();

	/*
	0 3
	2 6
	1 9*/
}
int main() {

	cout << solution({{ 0,3 }, { 1,9 }, { 2,6 }});


}