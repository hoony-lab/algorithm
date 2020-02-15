// 다음과 같이 include를 사용할 수 있습니다.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string commands) {
    // 여기에 코드를 작성해주세요.
    vector<int> answer;
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    string commands = "URDDL";
    vector<int> ret = solution(commands);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 {";
    for(int i = 0; i < ret.size(); i++){
        if (i != 0) cout << ", ";
        cout << ret[i];
    }
    cout << "} 입니다." << endl;
}