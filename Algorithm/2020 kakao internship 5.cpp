#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define F(i, n) for(int i = 0 ; i < n ; ++i)

#define MAX 200001
using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;

vi room[MAX];
int room_state[MAX];
int answer = 0;
map<int, int> mp;
set<int> st;

void bfs(int num) {
	
	queue<int> q, qq;
	q.push(num); st.insert(num);

	while (!q.empty()) {
		int r = q.front(); q.pop();

		for (int nr : room[r]) {

			if (st.count(nr)) continue;
			//cout << nr << '\n';
			if (room_state[nr] == -1) continue;

			

			if (room_state[nr] == 1) {
				//cout << "got the key !\n";
				room_state[nr] = 0;
				room_state[mp[nr]] = 0;
			}
			q.push(nr); st.insert(nr);
		}
	}
	
}
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {


	for (vi p : path) {
		room[p[0]].push_back(p[1]);
		room[p[1]].push_back(p[0]);
	}
	for (vi o : order) {
		mp[o[0]] = o[1];

		room_state[o[0]] = 1;		// key
		room_state[o[1]] = -1;	// lock
	}

	bfs(0);
	int time = 0;
	while (1) {
		//cout <<"\nTIME : " << time++ << '\n';
		
		for (vi o : order) {
			if(room_state[o[1]] != -1)
				bfs(o[1]);
		}
		//cout << st.size();

		if (st.size() == n)			return true;
		if (st.size() == answer)	return false;
		
		answer = st.size();
	}
	return false;
}


int main() {


	//solution(9, { {0, 1}, {0, 3}, {0, 7}, {8, 1}, {3, 6}, {1, 2}, {4, 7}, {7, 5} }, { {8, 5}, {6, 7}, {4, 1} }) ?
	//	cout << "TRUE" : cout << "FALSE";

	cout << "\n\n\n";
	solution(9, {{8, 1}, {0, 1}, {1, 2}, {0, 7}, {4, 7}, {0, 3}, {7, 5}, {3, 6}}, {{4, 1}, {5, 2}} ) ?
		cout << "TRUE" : cout << "FALSE";
	cout << "\n\n\n";

	//solution(9, {{0, 1}, {0, 3}, {0, 7}, {8, 1}, {3, 6}, {1, 2}, {4, 7}, {7, 5}}, {{4, 1}, {8, 7}, {6, 5}} ) ?
	//	cout << "TRUE" : cout << "FALSE";


	return 0;
}