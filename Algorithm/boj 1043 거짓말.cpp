#include <iostream>
#include <cstring>
#include <set>
// 지민이가 거짓말쟁이로 알려지지 않으면서
// 과장된 이야기를 할 수 있는 파티 개수의 최댓값
// 진실이가 있으면 그 친구들 다 진실됨

std::set<int> truth_ppl;
int ans, n, m, truth_ppl_cnt, temp, fail, party_ppl[51][51];

int main() {
	std::cin >> n >> m >> truth_ppl_cnt;

	for (int i = 0; i < truth_ppl_cnt; i++) {
		std::cin >> temp;
		truth_ppl.insert(temp);
	}

	for (int i = 1; i <= m; i++) {
		std::cin >> temp;
		party_ppl[i][0] = temp;

		for (int j = 1; j <= temp; j++)
			std::cin >> party_ppl[i][j];

	}

	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= m; i++) {

			fail = false;

			for (int num = 1; num <= party_ppl[i][0]; num++) {
				for (int truth : truth_ppl) {
					if (truth == party_ppl[i][num]) {
						fail = true;
					}
				}
			}
			if (fail) {
				for (int num = 1; num <= party_ppl[i][0]; num++)
					truth_ppl.insert(party_ppl[i][num]);
			}

		}
	}

	for (int i = 1; i <= m; i++) {

		fail = false;

		for (int num = 1; num <= party_ppl[i][0]; num++) {
			for (int truth : truth_ppl) {
				if (truth == party_ppl[i][num]) {
					fail = true;
				}
			}
		}

		if (!fail) ans++;
		
	}

	std::cout << ans;
	return 0;
}
/*
4 3
1 1
2 1 2
1 3
3 2 3 4

4 3
1 4
2 1 2
1 3
3 2 3 4
*/