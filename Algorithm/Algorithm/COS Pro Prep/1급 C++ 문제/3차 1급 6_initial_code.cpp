#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> primes = {2};
    for (int i = 3; i <= n; i += 2) {
        bool is_prime = true;
        for (int j = 2; j < i; j++) 
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        if (@@@)
            primes.push_back(i);
    }
    int prime_len = primes.size();
    for (int i = 0; i < prime_len - 2; i++)
        for (int j = i + 1; j < prime_len - 1; j++)
            for (int k = j + 1; k < prime_len; k++)
                if (@@@)
                    answer++;
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int n1 = 33;
    int ret1 = solution(n1);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

    int n2 = 9;
    int ret2 = solution(n2);
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}