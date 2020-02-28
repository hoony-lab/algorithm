#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
	int n, message, consumers, time, index, answer = 0;
	bool done;
	queue<int> q[11];
	cin >> n >> consumers;
	for (int i = 0; i < n; ++i) {
		cin >> message;
		cout << " Â÷·Ê \n";
		time = 1e9, index = 0, done = false;
		for (int cons = 0; cons < consumers; ++cons) {
			//cout << cons << "¹øÂ° ¼Õ´Ô\n";
			if (q[cons].empty()) {
				q[cons].push(message);
				done = true;
				break;
			}
			else {
				//time = min(time , q.front());
				if (time > q[cons].front()) {
					//cout << "¿¡°Ô Ãß°¡·Î »ðÀÔ\n";
					time = q[cons].front();
					index = cons;
				}
			}
		}

		if (!done) {
			time = q[index].front() + message;
			q[index].pop();
			q[index].push(time);
		}


		for (int a = 0; a < consumers; ++a) {
			if(!q[a].empty())
			cout << q[a].front() << endl;
		}
	}

	for (int i = 0; i < consumers; ++i) {
		cout << q[i].front() << endl;
		answer = max(answer, q[i].front());
	}

	cout << answer;





	return 0;
}