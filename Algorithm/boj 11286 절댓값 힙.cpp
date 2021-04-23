#include <iostream>
#include <string>
#include <queue>
#include <map>
#define pii pair<int,int>
using namespace std;
map<int, int> m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t, n; cin >> t;
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	while (t--) {
		cin >> n;

		// x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우
		if (!n) {
			// 만약 배열이 비어 있는 경우인데 가장 작은 값을 출력하라고 한 경우에는 0을 출력
			if (pq.empty()) {
				cout << "\t0\n";
			}
			else {
				cout << "\t" <<  pq.top().second << '\n';
				pq.pop();
			}
		}
		// x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산
		else {
			pq.push({abs(n), n });
		}
	}
	return 0;
}