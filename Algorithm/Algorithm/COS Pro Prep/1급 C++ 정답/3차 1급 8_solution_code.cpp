#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int k, vector<int> student) {
    int answer = 0;
    for(int i = 0; i < student.size(); i++){
        student[i] -= 4*k;
        if(student[i] <= 0)
            continue;
        answer += (student[i] + k - 1) / k;
    }
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. main함수는 잘못된 부분이 없으니, solution함수만 수정하세요.
int main() {
    int k1 = 1;
    vector<int> student1 = {4, 4, 4, 4};
    int ret1 = solution(k1, student1);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;
    
    int k2 = 3;
    vector<int> student2 = {15, 17, 19, 10, 23};
    int ret2 = solution(k2, student2);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}