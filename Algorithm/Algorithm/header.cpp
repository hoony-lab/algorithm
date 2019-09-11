#include <iostream>
#include <vector>
#include <queue>	
#include <memory.h>
#include <algorithm>	
#include <functional>
#include <iomanip>
#include <string>
#include <math.h>

#define min(a,b) a < b ? a : b;
#define max(a,b) a > b ? a : b;
using namespace std;
int main() {
	//int n;
	//int min = 1e9;
	//int max = 0;
	//cin >> n;

	//int a;
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> a;
	//	min = min(a, min);
	//	max = max(a, max);
	//}
	//cout << min << " " << max;

	int n, a, min = 1e9, max = -1e9;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (min > a) min = a;
		if (max < a) max = a;
	}
	cout << min << " " << max;

	system("pause");
}
	//vector<vector<int>> v;
	//sort(v.begin(), v.end(), [](int a, int b) {

	//});

