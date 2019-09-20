#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 0;
	int total_weight = 0;
	int ind = 0;

	// 무게, 위치
	queue<pair<int, int> > q;   

	//// 하나 넣고 시작
	//q.push({ truck_weights[ind], ind });
	//total_weight += truck_weights[ind];
	//ind++;

	while (1) {
		if (ind > truck_weights.size()) break;
		//시간 증가
		++time;

		//다리에 아무것도 없을때
		if (q.empty()) {
			q.push({ truck_weights[ind], ind });
			total_weight += truck_weights[ind];
			ind++;
		}

		// 다리에 있는것 한 칸 옮기기
		else {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				int wei = q.front().first;
				int loc = q.front().second + 1;
				q.pop();

				if (loc <= bridge_length)
					q.push({ wei, loc });
			}

			if (total_weight + truck_weights[ind] <= weight) {
				q.push({ truck_weights[ind], ind });
				total_weight += truck_weights[ind];
				++ind;
			}

		}

	}

	cout << time;
	return time;
}
int main() {
	/*
2	10	[7,4,5,6]	8
100	100	[10]	101
100	100	[10,10,10,10,10,10,10,10,10,10]	110
	*/

	return solution(2, 10, { 7, 4, 5, 6 });
}