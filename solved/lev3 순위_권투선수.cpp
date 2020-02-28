#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <memory.h>
using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	int games = results.size();
	map<int, int> player_count;
	int player_win_lose[101][2] = { 0, };
	for (int game = 0; game < games; ++game) {
		for (int a = 0; a < 2; ++a) {

			if (player_count[results[game][a]]) {
				player_count[results[game][a]]++;
			}
			else{
				player_count[results[game][a]] = 1;

			}

		}
		player_win_lose[ results[game][0] ][0]++;
		player_win_lose[ results[game][1] ][1]++;
	}
	/*
	1 2		1 -1 0 0 0
	3 2		1 -2 1 0 0
	4 2		1 -3 1 1 0
	4 3		1 -3 2 1 0
	2 5		1 -2 2 1 -3
	
	*/
	vector<int> v;
	int count = n;
	bool find;

	while (--count) {
		find = false;

		for (int i = 1; i <= n; ++i) {
			if (count == player_count[i]) {
				find = true;
				v.push_back(i);
			}
		}
		if (1) {}
		else if (!find) break;
	}


	return v.size();
}

int main(){
	
	cout << solution(5, { {4, 3}, {4, 2},{3, 2},{1, 2},{2, 5} });
	//2

}



/*
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int d[101][101];
int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	for(int i=0;i < results.size(); ++i) {
		d[results[i][0]][results[i][1]]= 1;
		d[results[i][1]][results[i][0]]= -1;
	}

	for (int i = 1; i <= n; ++i){
		for (int from = 1; from <= n; from++){
			if (d[from][i] == 0) continue;

			for (int to = 1; to <= n; to++){
				if (d[from][i] == d[i][to])
					d[from][to] = d[from][i];
			}
		}
	}


	for (int i = 1; i <= n; i++){
		int sum = 0;

		for (int j = 1; j <= n; j++){
			if(d[i][j]!=0 && (i!=j)){
				sum++;
			}
		}
		if(sum==(n-1)){
			answer++;
		}
	}
	return answer;
}

*/
