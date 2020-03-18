#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t, ans;
	std::cin >> t;
	while (t--) {
		//std::priority_queue<int, std::vector<int>, std::greater<int>> pq_low;
		//std::priority_queue<int> pq_up, pq_low;
		//std::multiset<int>::iterator iter;
		std::multiset<int> m;
		long long n;
		std::cin >> n;
		for (long long i = 0; i < n; i++) {
			char ch;
			long long k;
			std::cin >> ch >> k;

			if (ch == 'I') {
				m.insert(k);
			}
			else if (ch == 'D') {
				if (!m.empty()) {
					if (k == -1) m.erase(m.begin());
					else m.erase(--m.end());
				}
					
			}
		}

		if (m.empty()) std::cout << "EMPTY" << '\n';
		else std::cout << *(--m.end()) << " " << *m.begin() << '\n';
		
		
	}

	return 0;
}