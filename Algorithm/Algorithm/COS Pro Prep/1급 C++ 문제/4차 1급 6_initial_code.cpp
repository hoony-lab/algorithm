#include <iostream>
#include <string>
#include <vector>

using namespace std;

int power(int base, int exponent) {
    int val = 1;
    for (int i = 0; i < exponent; i++)
        val *= base;
    return val;
}

vector<int> solution(int k) {
    vector<int> answer;

    int range = power(10, k);
    for (int i = range / 10; i < range; i++) {
        int current = i;
        int calculated = 0;
        while (current != 0) {
            @@@;
            @@@;
        }
        if (calculated == i)
            answer.push_back(i);
    }
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int k = 3;
    vector<int> ret = solution(k);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 { ";
    for(int i = 0; i < ret.size(); i++){
        if (i != 0) cout << ", ";
        cout << ret[i];
    }
    cout << " } 입니다." << endl;
}