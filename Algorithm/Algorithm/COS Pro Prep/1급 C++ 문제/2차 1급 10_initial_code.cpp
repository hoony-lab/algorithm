#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    s += '#';
    string answer = "";
    for(int i = 0; i < s.length(); ++i){
        if (s[i] == '0' && s[i+1] != '0')
            answer += "0";
        else
            answer += "1";
    }
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. main함수는 잘못된 부분이 없으니, solution함수만 수정하세요.
int main() {
    string s = "101100011100";
    string ret = solution(s);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}