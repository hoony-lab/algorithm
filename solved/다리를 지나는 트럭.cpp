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

	//for (int truck = 0; truck < truck_weights.size(); truck++)
	//{
	//	int tru = truck_weights[truck];
	//}


	// 하나 넣고 시작
	q.push({ truck_weights[ind], ind });
	total_weight += truck_weights[ind];
	ind++;

	while (!q.empty()) {
		// (ind >= truck_weights.size()) break;
		//시간 증가
		++time;
		cout << "시간 : " << time << '\n';
		//다리에 아무것도 없을때

		if (q.empty()) {
			cout << "다리에 없어..올려.. : " << ind << '\n';
			q.push({ truck_weights[ind] , ind });
			total_weight += truck_weights[ind];
			ind++;
		}

		// 다리에 있는것 한 칸 옮기기
		else {

			if (total_weight + truck_weights[ind] <= weight) {
				cout << "다리가 아직 가볍네 " << ind << "올리기 ! \n";
				q.push({ truck_weights[ind], ind });
				total_weight += truck_weights[ind];
				++ind;
			}

			int size = q.size();
			cout << "몇개있어 : " << size << "개\n";
			for (int i = 0; i < size; ++i) {
				int wei = q.front().first;
				int loc = q.front().second + 1;
				q.pop();

				//다리 탈출 트럭
				if (loc <= bridge_length){
					q.push({ wei, loc });
				}
				else 
					total_weight -= wei;
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

	//return solution(2, 10, {7, 4, 5, 6 });
	return solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 });

}