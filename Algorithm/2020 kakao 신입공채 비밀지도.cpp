#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define F(i ,n) for(int i = 0 ; i < n ; ++i)

vector<string> solution(int n, int arr1[], int arr2[]) {
	vector<string> ans;
	F(i, n) {
		string tmp;
		int overlap = arr1[i] | arr2[i];
		while (overlap) {
			if (overlap % 2) tmp = "#" + tmp;
			else tmp = " " + tmp;
			overlap /= 2;
		}
		ans.push_back(tmp);
	}
	return ans;
}

int main() {
	/// 1
	int n = 5;
	int arr1[] = { 9, 20, 28, 18, 11 };
	int arr2[] = { 30, 1, 21, 17, 28 };

	vector<string> v = solution(n, arr1, arr2);
	for (auto s : v) cout << s << ", ";

	cout << "\n\n";
	v.clear();
	/// 2
	n = 6;
	int arr3[] = { 46, 33, 33, 22, 31, 50 };
	int arr4[] = { 27, 56, 19, 14, 14, 10 };

	v = solution(n, arr3, arr4);
	for (auto s : v) cout << s << ", ";

	return 0;
}