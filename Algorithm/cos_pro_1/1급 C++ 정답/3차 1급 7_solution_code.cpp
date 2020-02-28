#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int k) {
	vector<int> answer;

	for (int i = 1; i <= k; i++) {
		long long square_num = i * i;
		long long divisor = 1;
		while (square_num / divisor != 0) {
			long long front = square_num / divisor;
			long long back = square_num % divisor;
			divisor *= 10;
			if (back != 0 && front != 0)
				if (front + back == i) {
					answer.push_back(i);
				}
		}
	}
	return answer;
}