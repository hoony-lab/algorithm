#include <iostream>
#define endl '\n'

int main() {
	int t;
	std::cin >> t;

	int people[15][15];
	for (int i = 0; i < 15; i++)
		people[0][i] = i, people[i][0] = 0;
	
	for (int j = 1; j < 15; j++) {
		for (int p = 1; p < 15; p++) {
			people[j][p] = people[j - 1][p] + people[j][p-1];
		}
	}

	for (int i = 0; i < t; i++) {
		int k, n;
		std::cin >> k >> n;
		std::cout << people[k][n] << endl;
	}

}
/*
	1 2 3 4		5
0	1 2 3 4		5
1	1 3 6 10	15
2	1 4 10 20	35
3	1 4 14 34	69
*/