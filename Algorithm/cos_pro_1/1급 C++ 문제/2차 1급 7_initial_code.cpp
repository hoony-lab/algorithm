#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int money) {
    int coin[8] = {10, 50, 100, 500, 1000, 5000, 10000, 50000};
    int counter = 0;
    int idx = 7;
    while (money > 0){
		counter += money / coin[idx];
        money %= coin[idx];
        idx -= 1;
		//counter += @@@;
  //      money %= @@@;
  //      idx -= @@@;
    }
    return counter;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int money = 2760;
    int ret = solution(money);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "solution 함수의 반환 값은 " << ret << " 입니다." << endl;
}