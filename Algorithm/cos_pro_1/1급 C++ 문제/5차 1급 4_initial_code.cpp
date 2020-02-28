#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int number) {
    string answer = "";

    vector<int> number_count(10);
    while(number > 0) {
        number_count[number % 10]++;
        number /= 10;
    }

    for(int i = 0; i < 10; i++)
        if(number_count[i] != 0)
            answer += (to_string(i) + to_string(number_count[i]));

    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. 아래에는 잘못된 부분이 없으니, 위의 코드만 수정하세요.
int main() {
	int number1 = 2433;
	string ret1 = solution(number1);
	
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

	int number2 = 662244;
	string ret2 = solution(number2);
	
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}