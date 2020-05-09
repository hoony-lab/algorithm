#include <iostream>
#include <string>
#include <vector>
#define F(i, n) for(int i = 0 ; i < n ; ++i)
#define FS(i, n, m) for(int i = m ; i < n ; ++i)
#define FR(i, n) for(int i = n - 1; i >= 0 ; --i)
using namespace std;
using vvi = vector<vector<int>>;
using vvs = vector<vector<string>>;
using vi = vector<int>;


string solution(vector<int> numbers, string hand) {
	string ans = "";
	vi l = { 3, 0 };
	vi r = { 3, 2 };

	for (int n : numbers) {

		if (n % 3 == 2 || n == 0) {
			if (n == 0) n = 11;

			int ldist = abs(l[0] - n / 3) + abs(l[1] - 1);
			int rdist = abs(r[0] - n / 3) + abs(r[1] - 1);

			if (ldist < rdist) {
				ans.append("L");
				l = { n / 3, 1 };
			}
			else if (ldist > rdist) {
				ans.append("R");
				r = { n / 3, 1 };
			}
			else {
				if (hand == "right") {
					ans.append("R");
					r = { n / 3, 1 };
				}
				else {
					ans.append("L");
					l = { n / 3, 1 };
				}
			}
		}

		else if (n % 3 == 1) {
			ans.append("L");
			l = { n / 3, 0 };
		}

		else if (n % 3 == 0) {
			ans.append("R");
			r = { (n / 3) - 1, 2 };
		}
	}
	return ans;
}


int main() {
	vvi key = { {0, 0, 0}, {1, 0, 0}, {0, 1, 1} };
	vvi key2 = { {1, 0}, {0, 1} };
	vvi lock = { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };


	vi numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};

	string hand = "right";		// "LRLLLRLLRRL"

	cout << solution(numbers, hand);

	return 0;
}