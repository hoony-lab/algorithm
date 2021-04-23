#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t, n; cin >> t;
	priority_queue<int, vector<int>, greater<int> > pq;
	/* 
	https://en.cppreference.com/w/cpp/container/priority_queue

	std::priority_queue<int> q;
	const auto data = {1,8,5,6,3,4,0,9,7,2};

	for(int n : data) q.push(n);

	print_queue(q);
	9 8 7 6 5 4 3 2 1 0
	>> default of pq's compare is "less" (최소힙, 제일 큰거 먼저)


	std::priority_queue<int, std::vector<int>, std::greater<int>>
		q2(data.begin(), data.end());

	print_queue(q2);
	0 1 2 3 4 5 6 7 8 9
	*/
	
	while (t--) {
		cin >> n;
		// x가 0이라면 배열에서 가장 작은 값을 출력하고 그 값을 배열에서 제거
		if (!n) {
			// 만약 배열이 비어 있는 경우인데 가장 작은 값을 출력하라고 한 경우에는 0을 출력
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		// x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산
		else {
			pq.push(n);
		}
	}
	return 0;
}