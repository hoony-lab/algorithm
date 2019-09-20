#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

bool solution(int x) {
	bool answer = true;
	int xx = x;
	int total = 0;
	string num = to_string(xx);
	
	for (int i = 0; i < num.size(); i++) {
		total += atoi(&num[i]);
	}
	if (x % total == 0) answer = true;
	else answer = false;
	return answer;
	
}
int main() {
	return solution(10);
}