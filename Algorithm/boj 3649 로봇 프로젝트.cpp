#include <iostream>
#include <vector>
#include <algorithm>
#define NANO 10'000'000
using vi = std::vector<int>;	vi v, v_match;
struct Ans { int s = 1e9, e = 1e9; } ans;
int main() {
	int x, t;	std::cin >> x >> t;		x *= NANO;

	while (t--) {
		int n;	std::cin >> n;	v.push_back(n);
	}
	
	std::sort(v.begin(), v.end());

	for (int i = 0; i < v.size() - 1; ++i) {
		int match = std::upper_bound(v.begin(), v.end(), x - v[i]) - v.begin() - 1;

		if (v[match] + v[i] != x) continue;
		
		//std::cout << match << " : " << v[match] << "\n";

		if (abs(ans.e - ans.s) < abs(v[match] - v[i]))
			ans.e = v[match], ans.s = v[i];
	}

	if(ans.s == 1e9)	std::cout << "danger ";
	else				std::cout << "yes "<< ans.s << " " << ans.e;

	return 0;
}