#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	int ind, temp;
	string str, strtemp;
	getline(cin, str, '\n');
	cin >> ind;

	vector<int> v;
	for (int i = 0; i < str.length(); i+=2) {
		temp = stoi(str.substr(i,i+1));
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	do {
		strtemp = "";
		
		for (int i = 0; i < v.size(); i++)
		{
			strtemp += to_string(v[i]);
		}
		if (!--ind) {
			cout << strtemp << endl;
			break;
		}
	}while(next_permutation(v.begin(), v.end()));
/*

	cout << endl << endl;
	for (auto i : answer) {
		cout << i << endl;
	}
	cout << strtemp[ind - 1];

*/


	return 0;
}