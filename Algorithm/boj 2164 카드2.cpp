#include <iostream>
#include <string>
#include <deque>
int main() {

	int n;
	std::cin >> n;
	std::string ans;
	//for (int i = 1; i <= n; ++i)
	//	ans.append(std::to_string(i));	
	//
	//while (1) {
	//	ans = ans.substr(1);

	//	if (ans.length() == 1) {
	//		std::cout << ans; 
	//		break;
	//	}

	//	ans = ans.substr(1, ans.size()-1) + ans.at(0);
	//}

	// time over

	std::deque<int> d;
	for (int i = 1; i <= n; ++i)
		d.push_back(i);

	while (d.size() != 1) {
		d.pop_front();
		d.push_back(d.front());
		d.pop_front();
	}
	std::cout << d.front();
	

	return 0;
}