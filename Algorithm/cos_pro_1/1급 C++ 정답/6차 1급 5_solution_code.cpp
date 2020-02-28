#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
	int answer = 0;

	vector<vector<int>> coins(4, vector<int>(4, 0));
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(i == 0 && j == 0)
				coins[i][j] = board[i][j];
			else if(i == 0 && j != 0)
				coins[i][j] = board[i][j] + coins[i][j-1];
			else if(i != 0 && j == 0)
				coins[i][j] = board[i][j] + coins[i-1][j];
			else
				coins[i][j] = board[i][j] + max(coins[i-1][j], coins[i][j-1]);
		}
	}

	answer = coins[3][3];
	return answer;
}