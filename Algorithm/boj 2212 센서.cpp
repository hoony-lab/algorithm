#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#define FIO std::ios_base::sync_with_stdio(false), std::cin.tie(NULL)

int main() {
	FIO;

	std::vector<int> sensors, dist;
	int n, k, tmp, ans = 0;
	std::cin >> n >> k;

	for (int i = 0; i < n; ++i) 
		std::cin >> tmp, sensors.push_back(tmp);

	std::sort(sensors.begin(), sensors.end());

	//for (int s : sensors) std::cout << s << "< ";

	for (int i = 0; i < n - 1; ++i) 
		dist.emplace_back(sensors[i+1] - sensors[i]);
	
	std::sort(dist.begin(), dist.end());

	for (int i = 0; i < n - k; i++)
		/*std::cout << dist[i] << ", " , */ ans += dist[i];
	
	std::cout << ans;

	return 0;
}
/*
6
2
1 6 9 3 6 7

1 - 3 - - 6 7 - 9		> 4, 22 > 26
  2    3  01  2
5
*/
