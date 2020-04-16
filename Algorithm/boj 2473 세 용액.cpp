#include <iostream>
#include <algorithm>
#include <vector>
#define FIO std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL);
#define ll long long
ll n, tmp, sum = 1e11, ans[3], done;
std::vector<ll> liquid;

int main() {
	FIO;

	std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> tmp, liquid.push_back(tmp);

	std::sort(liquid.begin(), liquid.end());
	
	//for (int start = 0; start < n - 2; start++) {
	//	for (int end = n - 1; end >= 2; end--) {

	//		for (int mid = start + 1; mid < end - 1; mid++) {

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

	for (int first = 0; first < n; ++first) {

		int start = first + 1;
		int end = n - 1;

		while (start < end /*|| !done*/) {
			//std::cout << "   at " << first << ", " << start << ", " << end << '\n';

			tmp = liquid[first] + liquid[start] + liquid[end];

			// llabs(ll)  << wtf
			if (sum > llabs(tmp)) {

				sum = llabs(tmp);
				ans[0] = liquid[first];
				ans[1] = liquid[start];
				ans[2] = liquid[end];
			}

			if (tmp < 0)		start++;
			else if(tmp > 0)	end--;
			else				break;
		}
		if (tmp == 0) break;
	}

	std::cout << ans[0] << " " << ans[1] << " " << ans[2];

	return 0;
}
/*
5
-2 1 -97 -2 98

sorted
-97 -6 -2 6 98
*/