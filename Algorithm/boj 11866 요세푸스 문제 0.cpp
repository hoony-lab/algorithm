#include <iostream>
#include <string>
using namespace std;

int main() {

	std::string s, ans;
	int n, k;
	std::cin >> n >> k;

	for (int i = 1; i <= n; ++i) s.append(std::to_string(i));
	
	for (int i = 1; i <= n; ++i) {
		//ans += s[3];
		string aa = s.erase(s.find('3'),1);
		std::cout << aa << '\n';
		
	}
	

		//ans += s.erase(s.find[s[3]]);

		std::cout << ans << ", ";

	/*std::cout << "<";
	for (int i = 0; i < n - 1; ++i)
		std::cout << ans[i] << ", ";
	std::cout << ans[n - 1] << ">";
*/

}
	/*
	123456712 / 345671234567
	  3  6  2  5  1  4  7

	1234567
	12 4567	3
	12 45 7	6
	1  45 7	2
	1  45	7
	1  4	5
	   4	1
			4
	*/