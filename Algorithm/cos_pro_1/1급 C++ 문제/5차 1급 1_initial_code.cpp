#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	vector<int> steps(n+1);
	steps[1] = 1;
	steps[2] = 2;
	steps[3] = 4;
	for(int i = 4; i <= n; i++)
		steps[i] = @@@;
	answer = steps[n];

	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int n1 = 3;
	int ret1 = solution(n1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	printf("solution 함수의 반환 값은 %d 입니다.\n", ret1);

	int n2 = 4;
	int ret2 = solution(n2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	printf("solution 함수의 반환 값은 %d 입니다.\n", ret2);
}