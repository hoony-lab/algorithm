#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
1 3 5 7
2 2 6 8
*/
int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	int size = A.size();

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	if (A[0] >= B[size - 1]) return 0;
	else if (A[size - 1] < B[0]) return size;

	int ind = -1;
	for (int i = 0; i < size; ++i) {

		while (ind < size) {
			++ind;
			if (A[i] < B[ind]) break;
		}
		if (ind >= size) break;
		++answer;
	}
	return answer;
}