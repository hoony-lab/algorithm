#include <string>
#include <iostream>
#include <vector>

using namespace std;

long long solution(int one_day_price, int multi_day, int multi_day_price, long long n) {
    if(one_day_price * multi_day <= multi_day_price)
        return n * one_day_price;
    else
        return (n % multi_day) * multi_day_price + (n / multi_day) * one_day_price;
}

// 아래는 테스트케이스 출력을 해보기 위한 코드입니다. 아래에는 잘못된 부분이 없으니, 위의 코드만 수정하세요.
int main() {
    int one_day_price1 = 3;
    int multi_day1 = 5;
    int multi_day_price1 = 14;
    long long n1 = 6;
    long long ret1 = solution(one_day_price1, multi_day1, multi_day_price1, n1);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret1 << " 입니다." << endl;

    int one_day_price2 = 2;
    int multi_day2 = 3;
    int multi_day_price2 = 5;
    long long n2 = 11;
    long long ret2 = solution(one_day_price2, multi_day2, multi_day_price2, n2);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret2 << " 입니다." << endl;
}