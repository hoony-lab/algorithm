// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> bishops) {
    // 여기에 코드를 작성해주세요.
    int answer = 0;
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    vector<string>  bishops1 = {"D5"};
    int ret1 = solution( bishops1);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

    vector<string>  bishops2 = {"D5", "E8", "G2"};
    int ret2 = solution( bishops2);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}