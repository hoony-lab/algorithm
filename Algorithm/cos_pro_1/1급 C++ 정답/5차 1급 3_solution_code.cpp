#include <vector>
#include <algorithm>

using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	
	sort(numbers.begin(), numbers.end());
	int mid = (numbers.size() - 1) / 2;
	swap(numbers[mid], numbers[numbers.size()-1]);

	int left = mid + 1;
	int right = numbers.size() - 2;
	while(left <= right) {
		swap(numbers[left], numbers[right]);
		left = left + 1;
		right = right - 1;
	}

	answer = numbers;
	return answer;
}