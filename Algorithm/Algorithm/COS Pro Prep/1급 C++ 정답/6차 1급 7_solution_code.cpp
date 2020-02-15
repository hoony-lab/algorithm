#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int K, vector<int> numbers, vector<string> up_down) {
    int left = 1;
    int right = K;
    for(int i = 0; i < numbers.size(); i++){
        int num = numbers[i];
        if(up_down[i] == "UP")
            left = max(left, num + 1);
        else if(up_down[i] == "DOWN")
            right = min(right, num - 1);
        else if(up_down[i] == "RIGHT")
            return 1;
    }
    return right - left + 1;
}