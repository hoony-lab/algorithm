#include <iostream>
#include <algorithm>
#include <vector>
#define FIO std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL);
#define ll long long
ll n, tmp, sum = 1e11, ans[3], start, end, mid;
std::vector<ll> liquid;

int main() {
	FIO;

	std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> tmp, liquid.push_back(tmp);

	std::sort(liquid.begin(), liquid.end());

	//for (start = 0; start < n - 2; start++) {
	//	for (end = n - 1; end >= 2; end--) {

	//		for (mid = start + 1; mid < end - 1; mid++) {

	//			tmp = abs(liquid[start] + liquid[end] + liquid[mid]);
	//			
	//			if (sum > tmp) {
	//				sum = tmp;
	//				ans[0] = liquid[start];
	//				ans[1] = liquid[mid];
	//				ans[2] = liquid[end];
	//				if (tmp == 0) break;
	//			}
	//		}

	//	}
	//}

	for (ll num : ans) std::cout << num << " ";

	return 0;
}
/*
5
-2 6 -97 -6 98

sorted
-97 -6 -2 6 98
*/