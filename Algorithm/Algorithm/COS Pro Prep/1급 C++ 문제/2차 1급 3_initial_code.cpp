#include <iostream>
#include <string>
#include <vector>

using namespace std;

int func_a(int n){
    int ret = 1;
    while(n > 0){
        ret *= 10;
        n--;
    }
    return ret;
}

int func_b(int n){
    int ret = 0;
    while(n > 0){
        ret++;
        n /= 10;
    }
    return ret;
}

int func_c(int n){
    int ret = 0;
    while(n > 0){
        ret += n%10;
        n /= 10;
    }
    return ret;
}

int solution(int num) {
    int next_num = num;
    while(true){
        next_num++;
        int length = func_@@@(@@@);
        if(length % 2)
            continue;
        int divisor = func_@@@(@@@);
        
        int front = next_num / divisor;
        int back = next_num % divisor;
        
        int front_sum = func_@@@(@@@);
        int back_sum = func_@@@(@@@);
        if(front_sum == back_sum)
            break;
    }
    return next_num - num;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int num1 = 1;
    int ret1 = solution(num1);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

    int num2 = 235386;
    int ret2 = solution(num2);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}