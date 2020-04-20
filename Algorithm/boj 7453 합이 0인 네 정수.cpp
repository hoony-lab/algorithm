#include <iostream>
#include <algorithm>
#include <vector>
#define FIO std::ios_base::sync_with_stdio(false), std::cin.tie(NULL);
#define MAX 4001

int A[MAX], B[MAX], C[MAX], D[MAX], n;
long long ans;
std::vector<int> vab, vcd;
int main() {
	FIO;

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> A[i] >> B[i] >> C[i] >> D[i];

	for (int a = 0; a < n; a++)
		for (int b = 0; b < n; b++)
			vab.emplace_back(A[a] + B[b]), vcd.emplace_back(C[a] + D[b]);

	std::sort(vab.begin(), vab.end());
	std::sort(vcd.begin(), vcd.end());

	//std::sort(num[0], num[0] + n);
	//std::sort(num[1], num[1] + n);
	//std::sort(num[2], num[2] + n);
	//std::sort(num[3], num[3] + n);

	int start = 0, end = n * n - 1;

	while (start < n * n && end > -1) {

		if (vab[start] + vcd[end] == 0) {
			
			//end_last = std::upper_bound(vcd.begin(), vcd.end(), -vab[start]) - vcd.begin();
			//start_first = std::lower_bound(vab.begin(), vab.end(), -vcd[end]) - vab.begin();

			int start_cnt = 0, end_cnt = 0;
			int tmp = vab[start];

			while (vcd[end] == -tmp && end > -1)
				start_cnt++, end--;
			while (vab[start] == tmp && start < n * n)
				end_cnt++, start++;
			
			ans += (long long)start_cnt * end_cnt;
		}
		
		else if (vab[start] + vcd[end] > 0) end--;
		else								start++;
	}
	std::cout << ans;

	return 0;
}

/*
6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45
*/