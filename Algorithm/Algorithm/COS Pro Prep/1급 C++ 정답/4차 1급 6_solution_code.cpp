#include <string>
#include <vector>
#include <iostream>

using namespace std;

int power(int base, int exponent) {
	int val = 1;
	for (int i = 0; i < exponent; i++) {
		val *= base;
	}
	return val;
}

vector<int> solution(int k) {
	vector<int> answer;

	int range = power(10, k);
	for (int i = range / 10; i < range; i++) {
		int current = i;
		int calculated = 0;
		while (current != 0) {
			calculated += power(current % 10, k);
			current = current / 10;
		}
		if (calculated == i)
			answer.push_back(i);
	}
	return answer;
}