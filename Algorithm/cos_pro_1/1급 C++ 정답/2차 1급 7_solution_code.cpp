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
    }
    return counter;
}