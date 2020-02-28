// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minus(int number) {
	return number - 1;
}
int plus(int number) {
	return number + 1;
}
int doubling(int number) {
	return number * 2;
}
int solution(int number, int target) {
	// 여기에 코드를 작성해주세요.
	int answer = 0;

	while (number != target) {
		if (number * 2 < target)
			answer++;
		else if(number - )
		if (number == target)
			break;
	}

	return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
	int number1 = 5;
	int target1 = 9;
	int ret1 = solution(number1, target1);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	int number2 = 3;
	int target2 = 11;
	int ret2 = solution(number2, target2);

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}