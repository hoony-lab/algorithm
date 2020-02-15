#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int arr_len = arr.size();
    vector<int> dp(arr_len, 1);
    for(int i = 1; i < arr_len; ++i)
        if(arr[i] > arr[i-1])
            dp[i] = dp[i-1] + 1;
    int answer = 0;
    for(int i = 0; i < arr_len; ++i)
        answer = answer < dp[i] ? dp[i] : answer;
    return answer;
}
