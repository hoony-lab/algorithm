#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<vector<int>> walls) {
	int answer = 0;

	for(int i = 0; i < walls.size(); i++) {
		for(int j = i+1; j < walls.size(); j++) {
			int area;
			if(walls[i][1] < walls[j][1])
				area = walls[i][1] * (walls[j][0] - walls[i][0]);
			else
				area = walls[j][1] * (walls[j][0] - walls[i][0]);

			if(answer < area)
				answer = area;
		}
	}

	return answer;
}